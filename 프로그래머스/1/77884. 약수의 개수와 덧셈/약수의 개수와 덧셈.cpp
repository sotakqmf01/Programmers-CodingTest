#include <string>
#include <vector>
#include <cmath>

using namespace std;

//int solution(int left, int right) {
//    int answer = 0;
//    
//    for(int i = left; i <= right; i++){   // left에서 right까지의 모든 수
//        ((int)sqrt(i) * (int)sqrt(i) == i) ? answer -= i : answer += i;
//    }
//    
//    return answer;
//}

int solution(int left, int right){
    int answer = 0;
    
    for(int i = left; i <= right; i++){
        (int)sqrt(i) * (int)sqrt(i) == i ? answer -= i : answer += i;
    }
    
    return answer;
}