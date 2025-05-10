#include <cmath>
#include <iostream>

using namespace std;

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
//        float currY = (float)w / h * x;
//        float prevY = (float)w / h * (x-1);
//        
//        int uselessCount = ceil(currY) - floor(prevY);
//        answer -= uselessCount;
//    }
//    
//    return answer;
//}