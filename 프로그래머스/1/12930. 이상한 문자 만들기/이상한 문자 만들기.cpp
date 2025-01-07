#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    
    int j = 0;
    for(int i = 0; i<len; i++){
        if(s[i] == ' '){
            j = 0;
            answer += s[i];
        }
        else{
            if(j % 2 == 0)
                answer += toupper(s[i]);
            else
                answer += tolower(s[i]);
            // j++를 for문의 증감식이 있는 곳에 넣어도 됨
            j++;
        }
    }
    
    return answer;
}