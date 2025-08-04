#include <string>
#include <vector>
#include <queue>

using namespace std;

// 곡괭이 문제와 비슷
// - 대신 경우의 수가 너무 많음 => DFS 사용하기 어려움

// 이런 문제는 바로바로 사용 유무를 바로바로 선택하기 어려움
// - a. 일단 라운드를 진행해보고,
// - b. 클리어할 수 없을 것 같을 때 [무적권] 사용

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    int nextRound = 0;
    
    // 1. [무적권] 없이는 진행할 없는 라운드 구하기
    //   - 해당 라운드를 맞닥뜨렸을 때가 [무적권]을 사용해야하는 시점
    // 2. [무적권] 사용 결정
    //   - [무적권]이 있는 경우, 가장 많은 적이 있는 라운드에서 사용
    //   - 없으면, 마지막으로 진행한 라운드 롤백
    while(nextRound < enemy.size()){
        pq.push(enemy[nextRound]);
        n -= enemy[nextRound];
        nextRound++;
        
        if(n >= 0)
            continue;
        else{
            // [무적권]을 어디선가 사용해야하는 시점
            if(k > 0){
                k--;    // 사용
                int numOfEnemy = pq.top();
                pq.pop();
                n += numOfEnemy;  
            }
            else{
                // [무적권]이 없으니 마지막으로 진행한 라운드 롤백
                nextRound--;
                break;
            }
        }
    }
            
    answer = nextRound;
    
    return answer;
}

// 다른 사람 풀이
//int solution(int n, int k, vector<int> enemy)
//{
//    int answer=0;
//
//    int idx=0;
//    priority_queue<int> pq;
//    while(idx < enemy.size())
//    {
//        if(n<enemy[idx] && k<=0) break;
//
//        n -= enemy[idx];
//        pq.push(enemy[idx]);
//        if(n < 0)
//        {
//            n += pq.top();
//            pq.pop();
//            k--;
//        }
//        idx++;
//    }
//    answer = idx;
//
//    return answer;
//}


// 내 코드를 개선한 ChatGPT 코드
//int solution(int n, int k, vector<int> enemy) {
//    priority_queue<int> pq;
//
//    for (int i = 0; i < enemy.size(); i++) {
//        pq.push(enemy[i]);
//        n -= enemy[i];
//
//        // 병사가 부족하면 무적권 사용
//        while (n < 0 && k > 0) {
//            n += pq.top();
//            pq.pop();
//            k--;
//        }
//
//        // 병사 부족하고 무적권도 없으면 여기서 종료
//        if (n < 0) 
//            return i;
//    }
//    return enemy.size(); // 전부 막은 경우
//}