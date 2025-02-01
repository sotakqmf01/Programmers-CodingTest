#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> TermsMap;
    int todayYear = stoi(today.substr(0, 4));
    int todayMonth = stoi(today.substr(5, 2));
    int todayDay = stoi(today.substr(8, 2));
    
    for(const string& term : terms)
    {
        char type = term[0]; // 약관 종류
        int expire = stoi(term.substr(2)); // 유효 기간
        TermsMap[type] = expire;
    }
    
    for(int i = 0; i < (int)privacies.size(); i++)
    {
        int Year = stoi(privacies[i].substr(0, 4));
        int Month = stoi(privacies[i].substr(5, 2));
        int Day = stoi(privacies[i].substr(8, 2));
        char type = privacies[i][11];
        
        int expireYear = Year + TermsMap[type] / 12;
        int expireMonth = Month + TermsMap[type] % 12;
        if(expireMonth > 12)
        {
            expireYear++;
            expireMonth -= 12;
        }
        int expireDay = Day - 1;
        if(expireDay < 1)
        {
            expireDay = 28;
            expireMonth--;
            if(expireMonth < 1)
            {
                expireMonth = 12;
                expireYear--;
            }
        }
        
        if(expireYear < todayYear)
            answer.push_back(i + 1);
        else if(expireYear == todayYear && expireMonth < todayMonth)
            answer.push_back(i + 1);
        else if(expireYear == todayYear && expireMonth == todayMonth && expireDay < todayDay)
            answer.push_back(i + 1);
    }
    
    return answer;
}