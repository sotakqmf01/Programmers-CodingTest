#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i < n; i++){
        if(n % i == 1){
            answer = i;
            break;
        }
    }
    
    return answer;
}

// 다른 사람 풀이
//int solution(int n){
//    int answer;
//        
//    // 홀수이면, 무조건 2
//    if(n % 2 == 1)
//        return 2;
//    
//    // 짝수이면, 홀수들 중에서 찾아야함
//    for(int i = 3; i < n; i += 2){
//        if(n % i == 1){
//            answer = i;
//            break;
//        }
//    }
//    
//    return answer;
//}