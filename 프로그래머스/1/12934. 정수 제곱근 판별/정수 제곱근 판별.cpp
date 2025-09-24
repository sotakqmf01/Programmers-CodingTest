#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 시간 초과
// i를 int로 하면 i*i가 [int]라 최댓값(약 21.5억)을 넘으면, 오버플로우 발생
// => 제한사항의 50조에 도달 못 함
// => for문 종료 조건 만족 불가능 => 무한 루프
//long long solution(long long n){
//    long long answer = -1;
//    
//    for(int i = 1; i*i <= n; i++){
//        if(i * i == n)
//            answer = (i + 1) * (i + 1);
//    }
//    
//    return answer;
//}

long long solution(long long n) {
    long long answer = 0;
    
    if (n == (long long)sqrt(n) * (long long)sqrt(n))
        answer = (long long)pow((sqrt(n) + 1), 2);
    else
        answer = -1;
    
    return answer;
}

//long long solution(long long n){
//    long long answer = -1;
//    
//    long long root = (long long)floor(sqrt(n));
//    if(root * root == n)
//        answer = (root + 1) * (root + 1);
//    
//    return answer;
//}