#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

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