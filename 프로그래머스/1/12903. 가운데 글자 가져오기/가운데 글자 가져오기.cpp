#include <string>
#include <vector>

using namespace std;

//string solution(string s) {
//    string answer = "";
//    int len = s.length();
//    
//    if(len % 2 == 1){
//        answer = s[len/2];
//    }
//    else{
//        answer = s.substr(len/2 - 1, 2);
//        //answer = s[len/2-1];
//        //answer += s[len/2];
//    }
//    
//    
//    return answer;
//}

string solution(string s){
    string answer = "";
    int length = s.length();
    
    if(length % 2 == 0)
        answer = s.substr((length / 2) - 1, 2);
    else
        answer = s.substr(length / 2, 1);
    
    return answer;
}