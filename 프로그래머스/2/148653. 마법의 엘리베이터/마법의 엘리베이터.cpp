#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 예시 2를 봤을 때
// 각 자리수에 대해서만 이동을 하면 되겠다는 생각이 들었음
// 1~9 중 5는 정중앙임 => 5인 경우에 어떻게 해야할 지가 고민
// - 45, 55, 65를 예시로 해보니 아래와 같은 로직
//   - 5보다 작은 경우, -버튼
//   - 5보다 큰 경우, +버튼
//   - 5인 경우, 앞 자리 수 보고 결정
//int solution(int storey) {
//    int answer = 0;
//    
//    // 각 자리 수
//    while(storey > 0){
//        int floor = storey % 10;
//        storey /= 10;
//        
//        if(floor < 5){
//            // abs()를 안해도 되지만 [-]버튼을 N번 누른 것처럼 보이기 위해 사용
//            answer += abs(-floor);
//        }
//        else if(floor > 5){
//            answer += 10 - floor;
//            storey++;
//        }
//        else
//        {
//            // 앞자리가 5보다 크거나 같은 경우 +버튼 누르기
//            // - 앞자리가 5인 경우엔 +버튼을 누르든 -버튼을 누르든 같음, 그냥 +버튼 누르는 것으로 한 것
//            if(storey % 10 >= 5){
//                answer += 5;
//                storey++;
//            }
//            else{
//                // 앞자리가 5보다 작으면 -버튼 누르기
//                answer += abs(-5);
//            }
//        }
//    }
//    
//    return answer;
//}

// 풀이2
// 
int getMinMagicStone(int num){
    if (num < 10) {
        // num : 내림
        // 10 - num + 1 : 올림하는 경우에는 다음 자리 수에 대해 버튼을 눌러줘야하니 +1
		return min(num, 10 - num + 1);
	}
    
    int minus = num % 10;
    int plus = 10 - num % 10;
    
    return min(getMinMagicStone(num/10 + 1) + plus, getMinMagicStone(num/10) + minus);
}

int solution(int storey){
    return getMinMagicStone(storey);
}