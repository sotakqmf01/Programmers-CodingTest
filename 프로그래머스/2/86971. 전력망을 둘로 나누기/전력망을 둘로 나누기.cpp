#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

// 기본 DFS 사용 방식
int DFS(int n, int start, const vector<vector<bool>>& adjacents){
    int visitedTowerCount = 0;
    vector<bool> visited(n+1, false);
    stack<int> st;
    
    st.push(start);
    
    while(!st.empty()){
        int currTower = st.top();
        st.pop();
        
        if(visited[currTower])
            continue;
        
        visitedTowerCount++;
        visited[currTower] = true;
        
        for(int i = 0; i < adjacents[currTower].size(); i++){
            if(adjacents[currTower][i]){
                st.push(i);
            }
        }
    }
    
    // 두 전력망의 송전탑 개수 차이
    return abs((n - visitedTowerCount) - visitedTowerCount);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 인접 행렬(wires의 값을 그대로 쓰기 위해 n+1 * n+1 배열)
    vector<vector<bool>> adjacents(n+1, vector<bool>(n+1, false));
    for(vector<int>& wire : wires){
        adjacents[wire[0]][wire[1]] = true;
        adjacents[wire[1]][wire[0]] = true;
    }
    
    // 각 wire 끊어서 한 쪽 전력망의 송전탑 개수 구하기(DFS or BFS)
    for(vector<int>& wire : wires){
        adjacents[wire[0]][wire[1]] = false;
        adjacents[wire[1]][wire[0]] = false;
        
        // 끊어진 쪽의 한 부분에서만 송전탑 개수 A를 구하면, 반대편 전력망의 송전탑 개수는 n - A
        int diff = DFS(n, wire[0], adjacents);
        answer = min(answer, diff);
        
        // 다음 wire을 끊었을 경우를 보기위해 원상 복구
        adjacents[wire[0]][wire[1]] = true;
        adjacents[wire[1]][wire[0]] = true;
    }
    
    return answer;
}

// ★★★서브 트리 방식
// - 트리 구조이므로 사이클 x => 부모로 되돌아가는 것만 안하면 됨
//void DFS(int curr, int prev, vector<vector<int>>& adjacents, vector<int>& subGraph){
//    subGraph[curr] = 1;
//    for(int& adjacent : adjacents[curr]){
//        // 그래프가 트리 형태지만 비방향성이라 3->4, 4->3이 될 수도 있어, 이를 방지하는 코드
//        if(adjacent == prev)
//            continue;
//        
//        DFS(adjacent, curr, adjacents, subGraph);
//        subGraph[curr] += subGraph[adjacent];
//    }
//}
//
//int solution(int n, vector<vector<int>> wires) {
//    int answer = n;
//    
//    // 인접 리스트
//    vector<vector<int>> adjacents(n + 1);
//    for(vector<int>& wire : wires){
//        adjacents[wire[0]].push_back(wire[1]);
//        adjacents[wire[1]].push_back(wire[0]);
//    }
//    
//    // v1번 노드를 기준으로 서브트리 개수
//    vector<int> subGraph(n + 1, 0);
//    DFS(wires[0][0], -1, adjacents, subGraph);
//    
//    // 각 전선 끊어보기
//    for(int i = 1; i < subGraph.size(); i++){
//        answer = min(answer, abs(n - subGraph[i] - subGraph[i]));
//    }
//    
//    return answer;
//}