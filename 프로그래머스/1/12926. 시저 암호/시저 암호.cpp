#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    //for(int c : s){
    //    if(c == ' '){
    //        answer += (char)c;
    //    }
    //    else if(c >= 'A' && c <= 'Z'){
    //        c += n;
    //        if(c > 'Z')
    //            c = c - 'Z' - 1 + 'A';
    //        answer += (char)c;
    //    }
    //    else{
    //        // 소문자에서 char형 오버플로우 발생할 수도 있음
    //        c += n;
    //        if(c > 'z')
    //            c = c - 'z' - 1 + 'a';
    //        answer += (char)c;
    //    }
    //}
    
    for(char& c : s){
        if(c == ' '){
            answer += c;
        }
        else{
            char alphabet = (c >= 'a') ? 'a' : 'A';
            answer += alphabet + (char)((c - alphabet + n) % 26);
        }
    }
    
    return answer;
}