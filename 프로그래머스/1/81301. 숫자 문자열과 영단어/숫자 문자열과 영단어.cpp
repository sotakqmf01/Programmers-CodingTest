#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    string str = "";
    
    for(int i = 0; i < len;)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            str += s[i];
            i++;
        }
        else
        {
            string twoAlphabet = s.substr(i, 2);
            if(twoAlphabet == "ze"){
                str += '0';
                i += 4;
            }
            else if(twoAlphabet == "on"){
                str += '1';
                i += 3;
            }
            else if(twoAlphabet == "tw"){
                str += '2';
                i += 3;
            }
            else if(twoAlphabet == "th"){
                str += '3';
                i += 5;
            }
            else if(twoAlphabet == "fo"){
                str += '4';
                i += 4;
            }
            else if(twoAlphabet == "fi"){
                str += '5';
                i += 4;
            }
            else if(twoAlphabet == "si"){
                str += '6';
                i += 3;
            }
            else if(twoAlphabet == "se"){
                str += '7';
                i += 5;
            }
            else if(twoAlphabet == "ei"){
                str += '8';
                i += 5;
            }
            else{
                str += '9';
                i += 4;
            }
        }
    }
    
    answer = stoi(str);
    
    return answer;
}