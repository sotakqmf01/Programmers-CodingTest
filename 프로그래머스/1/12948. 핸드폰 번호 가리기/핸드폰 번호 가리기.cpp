#include <string>
#include <vector>

using namespace std;

//string solution(string phone_number) {
//    string answer = "";
//    int len = phone_number.length();
//    
//    for(int i = 0; i < len; i++){
//        if(i < len-4)
//            answer += '*';
//        else
//            answer += phone_number[i];
//    }
//    
//    return answer;
//}

string solution(string phone_number){
    for(int i = phone_number.length() - 5; i >= 0; i--){
        phone_number[i] = '*';
    }
    
    return phone_number;
}