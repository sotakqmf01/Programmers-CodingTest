#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int flag = 1;
    int i = 0;
    
    if(s[0] == '+'){
        flag = 1;
        i = 1;
    }
    if(s[0] == '-'){
        flag = -1;
        i = 1;
    }
    for(i; i<s.length(); i++){
            answer = answer*10 + (s[i]-'0');  
    }
    
    answer *= flag;
    
    return answer;
}