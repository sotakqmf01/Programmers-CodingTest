#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 523과 52355를 비교하려면 한 자리씩 비교해 봐야함
// => 424/42442의 경우에 비교가 안됨
//        523/55
// idx1 - 012/34
//        523/52
// idx2 - 012/01
// 1+2 = 52352355
// 2+1 = 52355523 승
//--------------------------------------------
// 523과 52352를 비교
//        523/52
// idx1 - 012/34
//        523/52
// idx2 - 012/01
// 1+2 = 523/52352
// 2+1 = 52352/523 승
//--------------------------------------------
// 424과 42442를 비교
//        423/42
// idx1 - 012/34
//        423/42
// idx2 - 012/01
// 1+2 = 424/42/442 승
// 2+1 = 424/42/424 

bool Compare(const string& str1, const string& str2)
{
    //길이가 같으면 더 큰 값
    if(str1.length() == str2.length())
    {
        return str1 > str2;
    }
    else
    {
        // 길이가 다를 때는 두 문자열을 순서를 다르게해서 더하고 비교했을 때
        // 더 큰 경우의 앞에 붙은 문자열이 더 크다
        string str12 = str1 + str2;
        string str21 = str2 + str1;

        return str12 > str21;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    
    for(int num : numbers)
    {
        strings.push_back(to_string(num));
    }
    
    sort(strings.begin(), strings.end(), Compare);
    
    for(string& str : strings)
    {
        answer += str;
    }
    
    // [0, 0, 0] = 0
    if(answer[0] == '0')
        return "0";

    return answer;
}