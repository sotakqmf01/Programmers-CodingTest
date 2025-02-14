#include <string>
#include <vector>

using namespace std;

// 동적 계획법, 조합류의 문제
vector<long long> Mem(2000, -1);

long long solution(int n) {
    // 기저 사례
    if(n <= 0)
        return Mem[0] = 0;
    if(n == 1)
        return Mem[1] = 1;
    if(n == 2)
        return Mem[2] = 2;
    
    long long ReturnValue = Mem[n];
    if(Mem[n] != -1)
        return Mem[n];
    
    return Mem[n] = (solution(n-1) + solution(n-2)) % 1234567;
}