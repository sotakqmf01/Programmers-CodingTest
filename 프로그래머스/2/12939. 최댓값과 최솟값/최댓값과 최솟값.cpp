#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <sstream>

using namespace std;

//string solution(string s) {
//    string answer = "";
//    //string numStr;
//    long long num = 0;
//    long long min = LLONG_MAX;
//    long long max = LLONG_MIN;
//    //string::size_type sz;
//    
//    istringstream iss(s);
//
//    //while(getline(iss, numStr, ' '))
//    while(iss >> num)
//    {
//        //num = stoll(numStr);
//        min = num < min ? num : min;
//        max = num > max ? num : max;
//    }
//    
//    //while(!s.empty())
//    //{
//    //    num = stoll(s, &sz);
//    //    min = num < min ? num : min;
//    //    max = num > max ? num : max;
//    //    if(s.length() > sz) s = s.substr(sz);
//    //    else s = "";        
//    //}
//    
//    answer = to_string(min) + " " + to_string(max);
//    
//    return answer;
//}

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

string solution(string s){
    string answer = "";
    long long minValue = LLONG_MAX;
    long long maxValue = LLONG_MIN;
    
    istringstream iss(s);
    string numStr;
    long long num;
    
    while(getline(iss, numStr, ' ')){
        num = stoll(numStr);
        minValue = min(minValue, num);
        maxValue = max(maxValue, num);
    }
    
    answer = to_string(minValue) + " " + to_string(maxValue);
    
    return answer;
}