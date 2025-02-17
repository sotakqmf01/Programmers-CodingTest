#include <string>
#include <vector>

using namespace std;

bool CheckCorrect(string s)
{
    string CheckS = "";
    
    for(char c : s)
    {
        if(c == '[' || c == '{' || c == '(')
        {
            CheckS += c;
        }
        else
        {
            if(CheckS.back() == '[' && c == ']')
                CheckS.erase(CheckS.length() - 1);
            else if(CheckS.back() == '{' && c == '}')
                CheckS.erase(CheckS.length() - 1);
            else if(CheckS.back() == '(' && c == ')')
                CheckS.erase(CheckS.length() - 1);
            else
            {
                return false;
            }
        }
    }
    
    if(CheckS.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[0];
        s.erase(s.begin());
        s += c;
        
        if(CheckCorrect(s))
            answer++;
    }
    
    return answer;
}