#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// 한 축만 포함하는 상태로 하나의 사분면에 속하는 좌표 개수에 x4를 하면, 총 좌표 개수 구할 수 있음
// - (x > 0, y >= 0)인 구간에서 (r1)^2 <= x^2 + y^2 <= (r2)^2 를 만족하는 좌표를 구하면 됨
//   - 위 구간에 해당하는 전체 좌표에 대해 조건을 만족하는지 일일이 확인하는 것은 너무 비효율적 O(n^2)
//   - x 좌표를 기준으로 
//     - (r1)^2 <= x^2 + y^2 조건을 만족하는 y1
//     - x^2 + y^2 <= (r2)^2 조건을 만족하는 y2를 구하면
//     - [y1, y2] 구간에 속하는 정수값들이 조건을 만족하는 좌표 개수가 됨
long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(long long x = 1; x <= r2; x++){
        int min = (x <= r1 ? ceil(sqrt((long long)r1*r1 - x*x)) : 0);
        int max = floor(sqrt((long long)r2*r2 - x*x));
        
        answer += (long long)max - min + 1;
    }
    
    return answer*4;
}