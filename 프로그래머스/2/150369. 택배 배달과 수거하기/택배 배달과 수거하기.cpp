//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long answer = 0;
//
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//    if(n == 0)
//        return answer;
//    
//    // 가장 먼 곳부터
//    int deliveryCap = 0;
//    int pickupCap = 0;
//    bool visited = false;
//    int distance = 0;
//    for(int i = n - 1;  i >= 0; i--){
//        if(deliveries[i] == 0 && pickups[i] == 0){
//            n--;
//            continue;
//        }
//        
//        if(!visited){
//            distance = i + 1;
//            visited = true;
//        }
//        
//        // 배달
//        int deliveryRemain = cap - deliveryCap;
//        if(deliveryRemain > 0){
//            if(deliveries[i] >= deliveryRemain){
//                deliveries[i] -= deliveryRemain;
//                deliveryCap += deliveryRemain;
//            }
//            else{
//                deliveryCap += deliveries[i];
//                deliveries[i] = 0;
//            }
//        }
//        
//        // 수거
//        int pickupRemain = cap - pickupCap;
//        if(pickupRemain > 0){
//            if(pickups[i] >= pickupRemain){
//                pickups[i] -= pickupRemain;
//                pickupCap += pickupRemain;
//            }
//            else{
//                pickupCap += pickups[i];
//                pickups[i] = 0;
//            }
//        }
//        
//        if(deliveries[i] == 0 && pickups[i] == 0)
//            n--;
//        
//        if(cap == deliveryCap && cap == pickupCap)
//            break;
//    }
//    
//    // 거리 계산
//    answer += 2 * (distance);
//    
//    // n을 다음으로 방문할 가장 먼 집으로 사용
//    // - 그렇다고 n을 무조건 들려야하는 건 아닐 수 있음
//    solution(cap, n, deliveries, pickups);
//}

#include <vector>
using namespace std;

// 문제 플랫폼 시그니처에 맞춰 이름을 solution으로 두었습니다.
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long totalDistance = 0;
    long long pendingDeliveries = 0; // 현재 인덱스보다 오른쪽 구간에 남은 배달 상자 수
    long long pendingPickups   = 0;  // 현재 인덱스보다 오른쪽 구간에 남은 수거 상자 수

    // 가장 먼 집부터(오른쪽에서 왼쪽으로) 스윕
    for (int i = n - 1; i >= 0; --i) {
        pendingDeliveries += deliveries[i];
        pendingPickups    += pickups[i];

        // 이 위치 i까지 가야 할 일이 남아 있으면, 왕복을 반복
        while (pendingDeliveries > 0 || pendingPickups > 0) {
            // 이번 한 번의 출발로 i+1번 집까지 왕복
            totalDistance += static_cast<long long>(i + 1) * 2;

            // 한 번 출발할 때 배달/수거에서 각각 cap만큼 처리(그리디)
            pendingDeliveries -= cap;
            pendingPickups    -= cap;
        }
    }

    return totalDistance;
}