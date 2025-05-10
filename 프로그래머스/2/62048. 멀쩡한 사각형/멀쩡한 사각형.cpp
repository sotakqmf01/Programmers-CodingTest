#include <cmath>
#include <iostream>

using namespace std;

// Y = (w/h)X 그래프보다 밑에 있는 격자의 개수 세는 방식
// - 다만 큰 수의 나눗셈을 할 때 float를 사용하면 부동 소수점 정밀도가 떨어져, 오차가 클 수 있음
// - double을 쓰면 조금이나마 해결할 수 있지만, 근본적인 해결은 아님
//long long solution(int w,int h) {
//    long long answer = 0;
//    
//    for(int x = 0; x < h; x++){
//        double y = (double)w / h * x;
//        
//        answer += (int)floor(y);
//    }
//    
//    return answer * 2;
//}

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

// 다른 사람 풀이
// 간단히 말하면, 대각선이 지나가면서 잘라버리는 칸의 수를
//  “가로로 만나는 선의 수 + 세로로 만나는 선의 수 – 겹쳐 만나는 격자점의 수”
// 로 셌기 때문입니다.
// 
// 1. 가로(세로)선과의 만남
//  - 대각선은 가로 방향 격자선을 H번, 세로 방향 격자선을 W번 만납니다.
//  - (꼭짓점 제외하고) 선 하나를 넘을 때마다 새로운 칸으로 들어가니까, 일단 W+H만큼 칸을 건너갑니다.
//
// 2. 격자점(정수 좌표)에서의 중복 계산
//  - 그런데 대각선이 정확히 격자점(예: (i,j)가 둘 다 정수인 점)을 통과할 때는 
//    “가로선 넘어감 + 세로선 넘어감”을 동시에 한 번에 처리하게 돼서, 2번 세어졌던 겁니다.
//  - 직선 (0,0)→(W,H) 사이에 있는 정수 격자점의 개수(꼭짓점 제외)는 gcd(W,H)−1개이고, 
//    끝점 두 개를 포함하면 총 gcd(W,H)+1개지만, 들어가는 칸 카운트 관점에선 “중복된 횟수”가 gcd(W,H)가 됩니다.
// 
// 3. 결론
//  - 잘려 나간 칸 수 = W+H − gcd(W,H)
// 
// ▶ 이렇게 구해진 만큼의 칸이 통째로 잘려서 쓸 수 없고, 나머지 W×H − (W+H−gcd(W,H))가 사용할 수 있는 칸의 수가 되는 거죠.
long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    long long useless = (long long)w+h - gcd(w, h);
    
    return answer - useless;
}