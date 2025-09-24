#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//string solution(vector<string> seoul) {
//    string answer = "";
//    int n = 0;
//    
//    for(int i = 0; i < seoul.size(); i++){
//        if(seoul[i] == "Kim")
//            n = i;
//    }
//    
//    answer = "김서방은 " + to_string(n) + "에 있다";
//    
//    return answer;
//}

//string solution(vector<string> seoul){
//    string answer = "";
//    
//    for(int i = 0; i < seoul.size(); i++){
//        if(seoul[i] == "Kim")
//            answer = "김서방은 " + to_string(i) + "에 있다";
//    }
//    
//    return answer;
//}

string solution(vector<string> seoul){
    string answer = "";
    
    vector<string>::iterator it = find(seoul.begin(), seoul.end(), "Kim");
    
    answer = "김서방은 " + to_string(it - seoul.begin()) + "에 있다";
    
    return answer;
}