#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int ak = 0; ak <= d; ak += k)
    {
        int bk = (int)sqrt((long long)pow(d, 2) - (long long)pow(ak, 2));
        
        int bkCount = (bk / k) + 1; // + 1 은 0을 포함하기 위해
        answer += bkCount;
    }
    
    return answer;
}