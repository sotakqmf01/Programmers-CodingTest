#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//bool compare(const char& a, const char& b){
//    return a > b;
//}
//
//string solution(string s) {
//    string answer = "";
//    
//    sort(s.begin(), s.end(), compare);
//    answer = s;
//    
//    return answer;
//}


string solution(string s){
    string answer = s;
    
    sort(answer.begin(), answer.end(), greater<char>());
    
    return answer;
}