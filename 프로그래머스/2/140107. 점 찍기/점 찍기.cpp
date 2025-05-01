#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 좌표 (x,y)가 있다고 했을 때
// 거리 d가 있고, x 좌표만 안다고 했을 때
// y의 최댓값을 구할 수 있음
// 근데 이 y값도 bk의 형태를 가져야함
// => y보다 작거나 같고, bk의 형태를 가지는 값의 개수 = y / k
long long solution(int k, int d) {
    long long answer = 0;
    
    for(int ak = 0; ak <= d; ak += k)
    {
        int y = (int)sqrt((long long)pow(d, 2) - (long long)pow(ak, 2));
        
        int bkCount = (y / k) + 1; // + 1 은 0을 포함하기 위해
        answer += bkCount;
    }
    
    return answer;
}