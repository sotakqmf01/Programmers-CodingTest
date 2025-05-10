#include <cmath>
#include <iostream>

using namespace std;

// Y = (w/h)X 그래프보다 밑에 있는 격자의 개수 세는 방식
// - 다만 큰 수의 나눗셈을 할 때 float를 사용하면 부동 소수점 정밀도가 떨어져, 오차가 클 수 있음
// - double을 쓰면 조금이나마 해결할 수 있지만, 근본적인 해결은 아님
long long solution(int w,int h) {
    long long answer = 0;
    
    for(int x = 0; x < h; x++){
        double y = (double)w / h * x;
        
        answer += (int)floor(y);
    }
    
    return answer * 2;
}

//long long solution(int w,int h) {
//    long long answer = w * h;
//    
//    for(int x = 1; x <= h; x++){
//        double currY = (double)w / h * x;
//        double prevY = (double)w / h * (x-1);
//        
//        int uselessCount = (int)ceil(currY) - (int)floor(prevY);
//        answer -= uselessCount;
//    }
//    
//    return answer;
//}