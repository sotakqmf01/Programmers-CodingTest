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
            j++;
        }
    }
    
    return answer;
}