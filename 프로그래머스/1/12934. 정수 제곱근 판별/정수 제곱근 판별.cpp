#include <string>
#include <vector>
#include <cmath>

using namespace std;

//long long solution(long long n) {
//    long long answer = 0;
//    
//    if (n == (long long)sqrt(n) * (long long)sqrt(n))
//        answer = (long long)pow((sqrt(n) + 1), 2);
//    else
//        answer = -1;
//    
//    return answer;
//}

// 시간 초과
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

long long solution(long long n){
    long long answer = -1;
    
    long long root = (long long)floor(sqrt(n));
    if(root * root == n)
        answer = (root + 1) * (root + 1);
    
    return answer;
}