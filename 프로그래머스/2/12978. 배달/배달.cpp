#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

void Dijkstra(int totalTown, int start, const vector<vector<int>>& adjacents, vector<int>& best){
    int visitedCount = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(totalTown+1, false);
    
    // 시작노드(1번 노드) 세팅
    best[start] = 0;
    pq.emplace(0, start);
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int currTown = pq.top().second;
                
        pq.pop();
        
        if(visitedCount == totalTown)
            break;
        
        if(visited[currTown])
            continue;
        
        if(dist > best[currTown])
            continue;
        
        // 방문
        visitedCount++;
        visited[currTown] = true;
        
        for(int next = 1; next < adjacents[currTown].size(); next++){
            if(adjacents[currTown][next] != -1){
                // 발견
                int nextDist = dist + adjacents[currTown][next];
                if(nextDist < best[next]){
                    // 방문하지 않은 곳들 중에 발견했을 때 최단거리이면 계속 갱신
                    // 갱신될 때마다 이전에 push한 요소들은 뒤로 밀리게 됨
                    best[next] = nextDist;
                    pq.emplace(nextDist, next);
                }
            }
        }
    }
}

int solution(int N, vector<vector<int>> roads, int K) {
    int answer = 0;
    // 인접 행렬
    vector<vector<int>> adjacents(N+1, vector<int>(N+1, -1));
    for(vector<int>& road : roads){
        if(adjacents[road[0]][road[1]] == -1){
            adjacents[road[0]][road[1]] = road[2];
            adjacents[road[1]][road[0]] = road[2];
        }
        else{
            if(adjacents[road[0]][road[1]] > road[2]){
                adjacents[road[0]][road[1]] = road[2];
                adjacents[road[1]][road[0]] = road[2];
            }
        }
    }
    
    // 각 노드별 1~N노드까지의 최단 거리
    vector<int> best(N+1, INT_MAX);
    // best를 채워줄 다익스트라
    Dijkstra(N, 1, adjacents, best);
        
    for(int i = 1; i <= N; i++){
        if(best[i] <= K)
            answer++;
    }
    
    return answer;
}