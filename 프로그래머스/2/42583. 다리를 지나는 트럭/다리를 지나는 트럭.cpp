#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int currentWeight = 0;
    int acrossTruckCount = 0;
    int nextTruck = 0;
    
    // 모든 트럭이 건너갈 동안 1초에 한 칸 씩 이동
    while(acrossTruckCount != truck_weights.size())
    {
        // 한 칸 씩 이동
        answer++;
        
        if(q.size() == bridge_length)
        {
            int truckWeight = q.front();
            if(truckWeight > 0)
            {
                currentWeight -= truckWeight;
                acrossTruckCount++;
                q.pop();
            }
            else
            {
                q.pop();
            }
        }
        
        if(acrossTruckCount == truck_weights.size())
        {
            break;
        }
        
        if(currentWeight + truck_weights[nextTruck] <= weight)
        {
            currentWeight += truck_weights[nextTruck];
            q.push(truck_weights[nextTruck]);
            if(nextTruck + 1 < truck_weights.size())
            {
                nextTruck++;
            }
        }
        else
        {
            // 다리의 빈 자리 표현 - 빈 칸을 queue에 넣음
            q.push(-1);
        }     
    }
    
    return answer;
}