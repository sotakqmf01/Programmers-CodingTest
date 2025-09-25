#include <string>
#include <vector>

using namespace std;

// 동적 계획법, 조합 류, 경우의 수 문제
vector<long long> Mem(2000, -1);

long long solution(int n) {
    // 기저 사례
    if(n <= 0)
        return Mem[0] = 0;
    if(n == 1)
        return Mem[1] = 1;
    if(n == 2)
        return Mem[2] = 2;
    
    // 기저 사례가 아닌 경우
    // 이미 값을 구해서 배열에 있는지 확인
    long long ReturnValue = Mem[n];
    if(Mem[n] != -1)
        return Mem[n];
    
    return Mem[n] = (solution(n-1) + solution(n-2)) % 1234567;
}

//long long solution(int n){
//    vector<long long> jump(n + 1, 0);
//    
//    jump[0] = 0;
//    jump[1] = 1;
//    jump[2] = 2;
//    
//    for(int i = 3; i <= n; i++){
//        jump[i] = (jump[i-1] + jump[i-2]) % 1234567;
//    }
//        
//    return jump[n];
//}