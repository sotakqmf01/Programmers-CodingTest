#include <iostream>
#include <cmath>

using namespace std;

// 비트 연산자 사용해야하면 어떻게 할지 생각해보기
//int solution(int n, int a, int b)
//{
//    int Round = 1;
//
//    while(Round <= n)
//    {
//        if((a+1)/2 == (b+1)/2)
//        {
//            break;
//        }
//        else
//        {
//            a = (a+1)/2;
//            b = (b+1)/2;
//        }
//
//        Round++;
//    }
//
//    return Round;
//}


int solution(int n, int a, int b){
    int answer = 1;

    while(1){
        a = (a - 1) / 2 + 1;  // = (a + 1) / 2
        b = (b - 1) / 2 + 1;
        
        // 서로 붙게 된다면, 둘 중 이겼을 때 다음 번호는 같음
        if(a == b)
            break;
        
        answer++;
    }
    
    return answer;
}

// 비트 연산 사용
//int solution(int n, int a, int b){
//    int answer = 0;
//    
//    while(a != b){
//        a = (a + 1) >> 1;   // = (a + 1) / 2
//        b = (b + 1) >> 1;
//        
//        answer++;
//    }
//    
//    return answer;
//}