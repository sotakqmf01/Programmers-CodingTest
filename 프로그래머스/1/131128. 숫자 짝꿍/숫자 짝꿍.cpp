#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    unordered_multiset<char> umset;
    
    for(char c : Y)
    {
        umset.insert(c);
    }
    
    for(int i = 0; i < X.size(); ++i)
    {
        unordered_multiset<char>::iterator it = umset.find(X[i]);
        if(it != umset.end())
        {
            answer += X[i];
            umset.erase(it);
        }
    }
    
    sort(answer.begin(), answer.end(), greater<int>());
    
    if(answer == "")
    {
        return "-1";
    }
    if(answer[0] == '0')
    {
        return "0";
    }
    
    return answer;
}