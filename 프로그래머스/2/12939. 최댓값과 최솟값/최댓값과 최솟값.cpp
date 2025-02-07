#include <string>
#include <vector>
#include <limits.h>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    long long num = 0;
    long long min = LLONG_MAX;
    long long max = LLONG_MIN;
    
    istringstream iss(s);
    
    while(iss >> num)
    {
        min = num < min ? num : min;
        max = num > max ? num : max;
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}