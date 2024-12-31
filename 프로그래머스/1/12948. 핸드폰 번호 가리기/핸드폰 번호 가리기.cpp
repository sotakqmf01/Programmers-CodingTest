#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int len = phone_number.length();
    
    for(int i = 0; i < len; i++){
        if(i < len-4)
            answer += '*';
        else
            answer += phone_number[i];
    }
    
    return answer;
}