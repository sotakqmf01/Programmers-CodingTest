#include <string>
#include <vector>
#include <cmath>

using namespace std;

//long long solution(int a, int b) {
//    long long answer = 0;
//    
//    if(a < b){
//        for(int i = a; i <= b; i++)
//            answer += i;
//    }
//    else if(a > b){
//        for(int i = b; i <= a; i++)
//            answer += i;
//    }
//    else{
//        answer = a;
//    }
//    
//    return answer;
//}

long long solution(int a, int b){
    return (long long)(a + b) * (long long)(abs(b - a) + 1) / 2;
}