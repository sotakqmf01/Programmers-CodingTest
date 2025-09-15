#include <string>
#include <vector>

using namespace std;

// solution을 재귀로 돌리면 벡터의 복사가 일어나서 시간이 너무 오래 걸림
// => 따로 빼서 참조로 받음 => 18~20은 통과 / 16,17 시간 초과
long long recursive(int cap, int n, vector<int>& deliveries, vector<int>& pickups){
    long long total = 0;
    
    auto farthest = [&](int n) -> int {
        for(int i = n - 1; i >= 0; i--)
            if(deliveries[i] > 0 || pickups[i] > 0) 
                return i + 1;
        return 0;
    };
    
    // 가장 먼 곳부터
    int deliveryCap = 0;
    int pickupCap = 0;
    //bool visited = false;
    int distance = farthest(n);
    
    if(distance == 0)
        return 0;

    for(int i = distance - 1;  i >= 0; i--){
        //if(deliveries[i] == 0 && pickups[i] == 0){
        //    n--;
        //    continue;
        //}
        
        //if(!visited){
        //    distance = i + 1;
        //    visited = true;
        //}
        
        // 배달
        int deliveryRemain = cap - deliveryCap;
        if(deliveryRemain > 0){
            if(deliveries[i] >= deliveryRemain){
                deliveries[i] -= deliveryRemain;
                deliveryCap += deliveryRemain;
            }
            else{
                deliveryCap += deliveries[i];
                deliveries[i] = 0;
            }
        }
        
        // 수거
        int pickupRemain = cap - pickupCap;
        if(pickupRemain > 0){
            if(pickups[i] >= pickupRemain){
                pickups[i] -= pickupRemain;
                pickupCap += pickupRemain;
            }
            else{
                pickupCap += pickups[i];
                pickups[i] = 0;
            }
        }
        
        // 이 부분이 문제
        // - 중간에 0/0인 부분에서도 n을 빼버림
        //if(deliveries[i] == 0 && pickups[i] == 0)
        //    n--;
        
        if(cap == deliveryCap && cap == pickupCap)
            break;
    }
    
    // 거리 계산
    total += 2 * (distance);
    
    // n을 다음으로 방문할 가장 먼 집으로 사용
    // - 그렇다고 n을 무조건 들려야하는 건 아닐 수 있음
    //   - n을 줄이는 부분에 문제가 있음 => 매번 가장 오른쪽을 찾음 => 이걸 다음에 넘겨줌
    return total + recursive(cap, distance, deliveries, pickups);
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = recursive(cap, n, deliveries, pickups);
    
    return answer;
}


// ChatGPT
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
//{
//    long long totalDistance = 0;
//    long long pendingDeliveries = 0; // 현재 인덱스보다 오른쪽 구간에 남은 배달 상자 수
//    long long pendingPickups   = 0;  // 현재 인덱스보다 오른쪽 구간에 남은 수거 상자 수
//
//    // 가장 먼 집부터(오른쪽에서 왼쪽으로) 스윕
//    for (int i = n - 1; i >= 0; --i) {
//        pendingDeliveries += deliveries[i];
//        pendingPickups    += pickups[i];
//
//        // 이 위치 i까지 가야 할 일이 남아 있으면, 왕복을 반복
//        while (pendingDeliveries > 0 || pendingPickups > 0) {
//            // 이번 한 번의 출발로 i+1번 집까지 왕복
//            totalDistance += static_cast<long long>(i + 1) * 2;
//
//            // 한 번 출발할 때 배달/수거에서 각각 cap만큼 처리(그리디)
//            pendingDeliveries -= cap;
//            pendingPickups    -= cap;
//        }
//    }
//
//    return totalDistance;
//}