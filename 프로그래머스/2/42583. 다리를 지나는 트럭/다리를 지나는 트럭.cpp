#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int currentWeight = 0;
    int acrossTruckCount = 0;
    int nextTruckIndex = 0;
    // 다리를 queue로 표현
    queue<int> bridge;
    
    // 모든 트럭이 건너갈 동안
    while(acrossTruckCount != truck_weights.size())
    {
        // 1초에 한 칸 씩 이동
        answer++;
        
        // 다리의 끝에 도달하면, 맨 앞 트럭 제거 (한 칸 전진)
        if(bridge.size() == bridge_length)
        {
            int truckWeight = bridge.front();
            bridge.pop();
            
            // 양수는 트럭, 음수는 빈 자리
            if(truckWeight > 0)
            {
                currentWeight -= truckWeight;
                acrossTruckCount++;
            } 
        }

        // 기다리는 트럭이 있고, 다리의 한계 무게 내라면 새로운 트럭 진입
        if(nextTruckIndex < truck_weights.size() && currentWeight + truck_weights[nextTruckIndex] <= weight)
        {
            currentWeight += truck_weights[nextTruckIndex];
            bridge.push(truck_weights[nextTruckIndex]);
            nextTruckIndex++;
        }
        else
        {
            // 진입할 트럭이 없거나 무게 한계를 초과하면 빈 칸(0)을 추가하여 시간 경과를 표현
            // 다리의 빈 자리 표현 - 빈 칸을 queue에 넣음
            bridge.push(-1);
        }     
    }
    
    return answer;
}