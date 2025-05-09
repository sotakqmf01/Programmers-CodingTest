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
int solution(int storey) {
    int answer = 0;
    
    // 각 자리 수
    while(storey > 0){
        int floor = storey % 10;
        storey /= 10;
        
        if(floor < 5){
            // abs()를 안해도 되지만 [-]버튼을 N번 누른 것처럼 보이기 위해 사용
            answer += abs(-floor);
        }
        else if(floor > 5){
            answer += 10 - floor;
            storey++;
        }
        else
        {
            // 앞자리가 5보다 크거나 같은 경우 +버튼 누르기
            // - 앞자리가 5인 경우엔 +버튼을 누르든 -버튼을 누르든 같음, 그냥 +버튼 누르는 것으로 한 것
            if(storey % 10 >= 5){
                answer += 5;
                storey++;
            }
            else{
                // 앞자리가 5보다 작으면 -버튼 누르기
                answer += abs(-5);
            }
        }
    }
    
    return answer;
}

// 다른 사람 풀이 - 재귀
//int getMinMagicStone(int num){
//    if (num < 10) {
//        // (num) : 내림
//        // (10 - num + 1) : 올림하는 경우에는 다음 자리 수에 대해 버튼을 눌러줘야하니 +1
//		return min(num, 10 - num + 1);
//	}
//    
//    int minus = num % 10;       // 내림
//    int plus = 10 - num % 10;   // 올림
//    
//    // (num/10) : 내림
//    // (num/10 + 1) : 올림하는 경우에는 다음 자리 수에 대해 버튼을 눌러줘야하니 +1
//    return min(getMinMagicStone(num/10) + minus, getMinMagicStone(num/10 + 1) + plus);
//}
//
//int solution(int storey){
//    return getMinMagicStone(storey);
//}

// GPT 풀이 - 같은 재귀이지만 또 조금 다르게 풀어서 보기 좋음
//int solve(vector<int>& digits, int pos, int carry) {
//    if (pos == digits.size()) {
//        // carry가 마지막에 남았다면 +1층 올라가는 버튼 1번 더
//        return carry;
//    }
//
//    // 현재 자리수의 층 수
//    int curr = digits[pos] + carry;
//
//    // 내리기 (버튼 curr번 누르기, 다음 carry 없음)
//    int down = solve(digits, pos + 1, 0) + curr;
//    // 올리기 (버튼 10 - curr번 누르기, 다음 carry 1)
//    int up = solve(digits, pos + 1, 1) + (10 - curr);
//
//    return min(down, up);
//}
//
//int solution(int storey) {
//    vector<int> digits;
//
//    // 자릿수 분해 (뒤에서부터)
//    while (storey > 0) {
//        digits.push_back(storey % 10);
//        storey /= 10;
//    }
//
//    return solve(digits, 0, 0);
//}