#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

//bool compare(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b){
//     if(a.second[0] != b.second[0])
//        return a.second[0] > b.second[0];
//    if(a.second[1] != b.second[1])
//        return a.second[1] > b.second[1];
//    // ☆ 마지막 광물이 5개로 딱 떨어지지 않을 수도 있으니까 돌 개수도 비교하는게 좋음
//    return a.second[2] > b.second[2];
//}
//
//int GetTiredness(const vector<int>& OrderOfPicks, const vector<pair<int, vector<int>>>& MineralsPerPick){
//    int Tiredness = 0;
//    
//    for(int i = 0; i<OrderOfPicks.size(); i++){
//        // 예외 체크를 해야함
//        if(i >= MineralsPerPick.size()){
//            break;
//        }
//        
//        if(OrderOfPicks[i] == -1){
//            continue;
//        }
//        else if(OrderOfPicks[i] == 3){
//            Tiredness += MineralsPerPick[i].second[0] * 1;
//            Tiredness += MineralsPerPick[i].second[1] * 1;
//            Tiredness += MineralsPerPick[i].second[2] * 1;
//        }
//        else if(OrderOfPicks[i] == 2){
//            Tiredness += MineralsPerPick[i].second[0] * 5;
//            Tiredness += MineralsPerPick[i].second[1] * 1;
//            Tiredness += MineralsPerPick[i].second[2] * 1;
//        }
//        else{
//            Tiredness += MineralsPerPick[i].second[0] * 25;
//            Tiredness += MineralsPerPick[i].second[1] * 5;
//            Tiredness += MineralsPerPick[i].second[2] * 1;
//        }
//    }
//    
//    return Tiredness;
//}
//
//int solution(vector<int> picks, vector<string> minerals) {
//    int answer = 0;
//    // 아래 배열들의 원소는 [순서]와 곡괭이 하나로 캘 수 있는 5개의 광물들 중 [다이아], [철], [돌]의 개수 저장
//    vector<pair<int, vector<int>>> MineralsPerPick; 
//    
//    // 광물 개수를 저장하는 배열 채우기
//    int Diamonds = 0;
//    int Irons = 0;
//    int Index = 0;
//    for(int i = 1; i <= minerals.size(); i++){
//        if(minerals[i - 1] == "diamond")
//            Diamonds++;
//        else if(minerals[i - 1] == "iron")
//            Irons++;
//        
//        if(i % 5 == 0 || i == minerals.size()){
//            if(i == minerals.size() && i % 5 != 0)
//                MineralsPerPick.emplace_back(Index, vector<int>{Diamonds, Irons, (i % 5) - Diamonds - Irons});
//            else
//                MineralsPerPick.emplace_back(Index, vector<int>{Diamonds, Irons, 5 - Diamonds - Irons});
//
//            Diamonds = 0;
//            Irons = 0;
//            Index++;
//        }
//    }
//    
//    int TotalPickCount = accumulate(picks.begin(), picks.end(), 0); // 총 곡괭이 개수
//    // 최대 곡괭이 개수를 사용하거나 광물을 전부 캤을 때까지만, 곡괭이 할당
//    int RequiredPickCount = min(TotalPickCount, (int)MineralsPerPick.size());
//    
//    // 내림차순 - 더 좋은 광물이 많은 순
//    // ★ 여기가 중요함
//    // - 곡괭이가 더 많을 때는 상관없지만,
//    // - 더 적을 때가 문제가 됨
//    //   - 마지막에 2개가 다이아이고 곡괭이 개수 안에 있는 5개의 광물이 돌이라고 했을 때, 
//    //   - 첫 제출 코드에서는 마지막 2개의 다이아가 순서상 앞으로 올 수 있게 됨
//    // => 광물을 순서대로 캐는게 아니게 됨
//    //sort(MineralsPerPick.begin(), MineralsPerPick.end(), compare); // 첫 제출 코드
//    sort(MineralsPerPick.begin(), MineralsPerPick.begin() + RequiredPickCount, compare);
//
//    // 광물들 중 다이아가 하나라도 존재하면 더 좋은 곡괭이를 써야함
//    // - 철도 마찬가지
//    // 다만, 가장 많이 들고 있는 순서대로 좋은 곡괭이를 먼저 할당
//    vector<int> OrderOfPicks(RequiredPickCount, -1); // 곡괭이 순서
//    for(int i = 0; i < RequiredPickCount; i++){
//        if(picks[0] > 0){
//            OrderOfPicks[i] = 3;
//            picks[0]--;
//        }
//        else if(picks[1] > 0){
//            OrderOfPicks[i] = 2;
//            picks[1]--;
//        }
//        else{
//            OrderOfPicks[i] = 1;
//        } 
//    }
//    
//    // 최종 : OrderOfPicks에는 사용할 곡괭이가, MineralsPerPick에는 해당 곡괭이로 체굴할 광물들이 저장
//    // - 피로도 구하기
//    answer = GetTiredness(OrderOfPicks, MineralsPerPick);
//    
//    return answer;
//}


// 다른 사람 풀이
// - 나랑 비슷한 구조를 가지고 있음. 하지만, 더 간단함
// - 각 곡괭이로 캘 수 있는 광물들을 배열로 저장했지만, 이 코드에선 111이 세 자리로 구현
//  - 100의 자리는 다이아의 수
//  - 10의 자리는 철의 수
//  - 1의 자리는 돌의 수
int solution(vector<int> picks, vector<string> minerals)
{
    int ans = 0;
    vector<int> v;
    int sum = 111;
    int k = 0;
    int d = picks[0];
    int i = picks[1];
    int s = picks[2];
    for(int i = 0; i < minerals.size(); i++)
    {
        if(minerals[i] == "diamond")
            sum += 100;
        else if(minerals[i] == "iron")
            sum += 10;
        else
            sum += 1;
        k++;
        if(k == 5 || i >= minerals.size()-1)
        {
            v.push_back(sum);
            sum = 111;
            k = 0; 
        }
    }
    
    int totalPicks = picks[0] + picks[1] + picks[2];
    int requiredPicks = min(totalPicks, (int)v.size());
    
    sort(v.begin(), v.begin() + requiredPicks, greater<>());
    for(int temp : v)
    {
        if(d > 0)
        {
            string str = to_string(temp);
            ans += ((str[0] - '0' - 1) * 1 + (str[1] - '0' - 1) * 1 + (str[2] - '0' - 1) * 1);
            d--;
        }
        else if(i > 0)
        {
            string str = to_string(temp);
            ans += ((str[0] - '0' - 1) * 5 + (str[1] - '0' - 1) * 1 + (str[2] - '0' - 1) * 1);
            i--;
        }
        else if(s > 0)
        {
            string str = to_string(temp);
            ans += ((str[0] - '0' - 1) * 25 + (str[1] - '0' - 1) * 5 + (str[2] - '0' - 1) * 1);
            s--;
        }
    }
    return ans;
}