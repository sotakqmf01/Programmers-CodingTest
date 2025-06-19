#include <string>
#include <vector>

using namespace std;

void Hanoi(int Plate, int Src, int Mid, int Dst, vector<vector<int>>& Ways){
    // 1. 원판이 1개인 경우 : 그냥 목표 기둥으로 옮기기
    if(Plate == 1){
        Ways.push_back(vector<int>({Src, Dst}));
        
        return;
    }
    
    // 2. 원판이 2개 이상인 경우
    // - 2.1. 가장 큰 원판을 제외한 나머지 원판들 보조 기둥으로 옮기기
    Hanoi(Plate - 1, Src, Dst, Mid, Ways);
    
    // - 2.2. 남아있는 가장 큰 원판을 목표 기둥으로 옮기기
    Ways.push_back(vector<int>({Src, Dst}));
    
    // - 2.3. 보조 기둥으로 옮긴 원판들을 목표 기둥으로 옮기기
    Hanoi(Plate - 1, Mid, Src, Dst, Ways);    
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    Hanoi(n, 1, 2, 3, answer);
    
    return answer;
}






















//int GetEmptyListIndex(const vector<list<int>>& Hanoi){
//    
//}
//
//vector<vector<int>> solution(int n) {
//    vector<vector<int>> answer;
//    vector<list<int>> Hanoi(3, list<int>());
//    
//    for(int i = n; n > 0; i--){
//        Hanoi[0].push_back(i);    
//    }
//    
//    int plate = Hanoi[0].back();
//    Hanoi[0].pop_back();
//    
//    if(n % 2 == 0){
//        Hanoi[1].push_back(plate);
//        answer.push_back({1, 2});
//    }
//    else{
//        Hanoi[2].push_back(plate);
//        answer.push_back({1, 3});
//    }
//    
//    while(Hanoi[2].size() != n){
//        int emptyIndex = GetEmptyListIndex(Hanoi);
//        int maxIndex = GetMaxIndex
//        if(emptyIndex != -1){
//            int maxIndex
//        }
//    }
//    
//    return answer;
//}