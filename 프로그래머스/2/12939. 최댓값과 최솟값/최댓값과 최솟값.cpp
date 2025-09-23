#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <sstream>

using namespace std;

// 1. istringstream 사용
//string solution(string s){
//    string answer = "";
//    long long minValue = LLONG_MAX;
//    long long maxValue = LLONG_MIN;
//    
//    istringstream iss(s);
//    long long num;
//    
//    while(iss >> num){
//        minValue = min(minValue, num);
//        maxValue = max(maxValue, num);
//    }
//    
//    answer = to_string(minValue) + " " + to_string(maxValue);
//    
//    return answer;
//}
//
//// 2. istringstream + getline()
//string solution(string s){
//    string answer = "";
//    long long minValue = LLONG_MAX;
//    long long maxValue = LLONG_MIN;
//    
//    istringstream iss(s);
//    string numStr;
//    long long num;
//    
//    while(getline(iss, numStr, ' ')){
//        num = stoll(numStr);
//        minValue = min(minValue, num);
//        maxValue = max(maxValue, num);
//    }
//    
//    answer = to_string(minValue) + " " + to_string(maxValue);
//    
//    return answer;
//}
//
//// 3. stoll() + substr()
//string solution(string s){
//    string answer = "";
//    long long minValue = LLONG_MAX;
//    long long maxValue = LLONG_MIN;
//    
//    long long num;
//    string::size_type sz;
//    
//    while(!s.empty()){
//        // stoll()에 사용되는 strtol()은 문자를 만나기 전까지 만난 공백을 지움
//        num = stoll(s, &sz);
//        minValue = min(minValue, num);
//        maxValue = max(maxValue, num);
//        
//        // 마지막에는 문자열의 길이와 sz의 값이 같기 때문에 빈 문자열 반환
//        s = s.substr(sz);
//    }
//    
//    answer = to_string(minValue) + " " + to_string(maxValue);
//    
//    return answer;
//}

// 4. string::find() + stoll() + substr()
string solution(string s){
    string answer = "";
    long long minValue = LLONG_MAX;
    long long maxValue = LLONG_MIN;
    
    long long num;
    size_t start = 0, end;
    while(1){
        end = s.find(' ', start);
        num = stoll(s.substr(start, end - start));
        
        minValue = min(minValue, num);
        maxValue = max(maxValue, num);
        
        start = end + 1;
        
        if(end == string::npos)
            break;
    }
    
    answer = to_string(minValue) + " " + to_string(maxValue);
    
    return answer;
}