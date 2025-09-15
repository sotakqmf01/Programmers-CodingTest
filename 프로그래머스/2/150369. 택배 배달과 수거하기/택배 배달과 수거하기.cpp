#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// solution을 재귀로 돌리면 벡터의 복사가 일어나서 시간이 너무 오래 걸림
// => 따로 빼서 참조로 받음 => 18~20 통과 / 16,17 시간 초과
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
    //   - n을 줄이는 부분에 문제가 있음 => 매번 가장 오른쪽을 찾음 => 이걸 다음에 넘겨줌 => farthest 찾을 때 좀 더 최적화
    //   - => 16,17 통과
    return total + recursive(cap, distance, deliveries, pickups);
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = recursive(cap, n, deliveries, pickups);
    
    return answer;
}


// ChatGPT
// - 배달/수거 왕복을 할 때마다 처리하는 방식
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
//{
//    long long totalDistance = 0;
//    long long deliveryRemain = 0;     // 현재 집에서의 남은 배달 상자 수
//    long long pickupRemain = 0;       // 현재 집에서의 남은 수거 상자 수
//
//    // 가장 먼 집부터(오른쪽에서 왼쪽으로) 스윕
//    for (int i = n - 1; i >= 0; --i) {
//        deliveryRemain += deliveries[i];
//        pickupRemain += pickups[i];
//
//        // 이 위치 i까지 가야 할 일이 남아 있으면, 왕복을 반복
//        while (deliveryRemain > 0 || pickupRemain > 0) {
//            // 이번 한 번의 출발로 i+1번 집까지 왕복
//            totalDistance += static_cast<long long>(i + 1) * 2;
//
//            // 한 번 출발할 때 배달/수거에서 각각 cap만큼 처리(그리디)
//            // - 음수가 되면 여유 용량이 있다는 것
//            //   - 다음 집에서 이 여유 용량에 그 집의 배달/수거 cap을 처리했을 때, 둘 다 음수이면
//            //   - 한 번의 왕복으로 해당 집까지 처리할 수 있다는 것 => while을 넘어감
//            deliveryRemain -= cap;
//            pickupRemain -= cap;
//        }
//    }
//
//    return totalDistance;
//}


// 다른 사람 풀이
// - ChatGPT와는 반대로 왕복 횟수를 구해서 한 번에 처리하는 방식
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//    long long answer = 0;
//
//    long long deliveryCap = 0;    // 누적 배달 개수
//    long long pickupCap = 0;      // 누적 수거 개수
//    for (int i = n - 1; i >= 0; i--)
//    {
//        if (deliveries[i] != 0 || pickups[i] != 0)
//        {
//            int roundTrip = 0;  // 왕복 횟수
//            // Cap이 남아 있으면, 왕복하지 않고 다음 집을 처리할 수 있음
//            // - 거리 누적할 때 roundTrip이 0이라 0이 누적됨
//            while (deliveryCap < deliveries[i] || pickupCap < pickups[i])
//            {
//                ++roundTrip;
//                deliveryCap += cap;
//                pickupCap += cap;
//            }
//            
//            deliveryCap -= deliveries[i];
//            pickupCap -= pickups[i];
//            
//            answer += (1LL * roundTrip) * (1LL * (i + 1)) * 2;
//        }
//    }
//
//    return answer;
//}


// ChatGPT - 투 포인터
//long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
//    long long totalDistance = 0;
//
//    // 각각 "배달/수거에서 아직 일이 남은 가장 먼 집 인덱스(0-based)"
//    int iDeliver = n - 1;
//    int iPick    = n - 1;
//
//    auto pullRight = [&](int& idx, const vector<int>& arr) {
//        while (idx >= 0 && arr[idx] == 0) --idx; // 0이면 왼쪽으로 당김
//    };
//
//    // 초기로 0 구간 스킵
//    pullRight(iDeliver, deliveries);
//    pullRight(iPick, pickups);
//
//    while (iDeliver >= 0 || iPick >= 0) {
//        // 이번 출발의 최장 거리 지점 (집 번호는 +1, 왕복이므로 ×2)
//        int farIndex = max(iDeliver, iPick);
//        totalDistance += 2LL * (farIndex + 1);
//
//        // 배달/수거는 서로 독립적으로 cap까지 처리
//        int remainDeliver = cap;
//        int remainPick    = cap;
//
//        // 배달: iDeliver에서 왼쪽으로 오며 remainDeliver를 소진
//        while (iDeliver >= 0 && remainDeliver > 0) {
//            if (deliveries[iDeliver] == 0) {
//                --iDeliver;
//                continue;
//            }
//            int used = min(remainDeliver, deliveries[iDeliver]);
//            deliveries[iDeliver] -= used;
//            remainDeliver        -= used;
//            if (deliveries[iDeliver] == 0) --iDeliver;
//        }
//
//        // 수거: iPick에서 왼쪽으로 오며 remainPick을 소진
//        while (iPick >= 0 && remainPick > 0) {
//            if (pickups[iPick] == 0) {
//                --iPick;
//                continue;
//            }
//            int used = min(remainPick, pickups[iPick]);
//            pickups[iPick] -= used;
//            remainPick     -= used;
//            if (pickups[iPick] == 0) --iPick;
//        }
//
//        // 다음 라운드 시작 전에 0 구간 스킵(안 해도 위 while에서 처리되지만 명시적으로 안전)
//        pullRight(iDeliver, deliveries);
//        pullRight(iPick, pickups);
//    }
//
//    return totalDistance;
//}