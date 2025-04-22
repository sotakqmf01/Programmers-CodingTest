#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    long long sumOfQ1 = 0;
    long long sumOfQ2 = 0;
    
    for(int i = 0; i < queue1.size(); i++){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        
        sumOfQ1 += queue1[i];
        sumOfQ2 += queue2[i];
    }
    
    // [반례 11, 28] : 모든 원소의 합이 홀수
    // arr1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 10 }
    // arr2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    // => 모든 원소의 합이 홀수인 경우 무한으로 티키타카되는 부분이 있음
    // 두 큐의 합이 같아야 한다고할 때 생각했는데;;;
    if((sumOfQ1 + sumOfQ2) % 2 != 0)
        return -1;
    
    // [반례] : 모든 원소의 합이 짝수이지만, 어떤 경우에도 총합의 절반을 만들지 못하는 경우(무한 반복)
    // queue1 = [1, 1]
    // queue2 = [1, 5]
    // => 연산 횟수 제한 3 * queue.size()
    int maxCount = 3 * queue1.size();
    while(answer <= maxCount){
        if(sumOfQ1 == sumOfQ2)
            return answer;
        // [반례]
        // queue1 = [1, 1, 1, ..., 1, 1000000]  // 길이 300000
        // queue2 = [1, 1, 1, ..., 1]           // 길이 300000
        // => queue1에서 100만을 제외하고 전부 queue2로 옮겼을 때도 합이 같지 않음 => 절대 두 큐의 합은 같아질 수 없음
        //    queue1에서 100만을 넘기는 시점에 queue1은 empty()가 됨
        if(q1.empty() || q2.empty())
            return -1;
        
        if(sumOfQ1 > sumOfQ2){
            int front = q1.front();
            q1.pop();
            q2.push(front);
            
            // 조금 다르긴 한데 [슬라이딩 윈도우]라는 방식과 유사
            sumOfQ1 -= front;
            sumOfQ2 += front;
        }
        else{
            int front = q2.front();
            q2.pop();
            q1.push(front);
            
            sumOfQ2 -= front;
            sumOfQ1 += front;
        }
        
        answer++;
    }
    
    return -1;
}

// ChatGPT가 가르쳐준 문제의 본질
// - queue1 + queue2 → 하나의 배열 [A1, A2, ..., An, B1, B2, ..., Bn] 이라고 생각 가능
// - 이 배열 안에서 연속된 구간을 슬라이딩하면서 합이 (sum1 + sum2) / 2가 되는 지점을 찾는 문제
// ▶ 이론적으로는 2n이면 충분
// ▶ 다만 큐 구조로 로직 짜면 무한 반복 방지를 위해 3n 정도로 컷오프 걸어주는 게 안정성 측면에서 실전에서 더 많이 쓰임
//   3n인 이유? 한 쪽으로 몰아야할 때 [n번], 그럼 몰린 쪽 queue의 길이는 2n
//             다시 반대쪽으로 몰아보면 [2n번]
//   ※ 총 3n번이면 한쪽에 몰았다가 반대쪽으로 몰면서 모든 경우를 다 볼 수 있음
