#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    if (n == (long long)sqrt(n) * (long long)sqrt(n))
        answer = (long long)pow((sqrt(n) + 1), 2);
    else
        answer = -1;
    
    return answer;
}