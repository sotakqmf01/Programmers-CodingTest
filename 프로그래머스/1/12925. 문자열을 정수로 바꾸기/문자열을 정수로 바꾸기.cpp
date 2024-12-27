#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int flag = 1;
    
    
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '+')
            flag = 1;
        else if(s[i] == '-')
            flag = -1;
        else
            answer = answer*10 + (s[i]-'0');  
    }
    
    answer *= flag;
    
    return answer;
}