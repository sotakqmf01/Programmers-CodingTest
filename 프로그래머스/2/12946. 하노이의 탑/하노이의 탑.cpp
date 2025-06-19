#include <string>
#include <vector>

using namespace std;

void Hanoi(int Plate, int Src, int Mid, int Dst, vector<vector<int>>& Ways){
    // 1. 원판이 1개인 경우 : 그냥 목표 기둥으로 이동
    if(Plate == 1){
        Ways.push_back(vector({Src, Dst}));

        return;
    }
    
    // 2. 원판이 2개 이상인 경우
    // - 2.1. 가장 큰 원판을 제외한 나머지 원판들 보조 기둥으로 옮기기
    Hanoi(Plate - 1, Src, Dst, Mid, Ways);
    
    // - 2.2. 남아있는 가장 큰 원판을 목표 기둥으로 이동
    Ways.push_back(vector({Src, Dst}));
    
    // - 2.3. 보조 기둥에 있는 것을 목표 기둥으로 이동
    Hanoi(Plate - 1, Mid, Src, Dst, Ways);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    Hanoi(n, 1, 2, 3, answer);
    
    return answer;
}