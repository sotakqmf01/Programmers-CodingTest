#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//vector<int> solution(vector<string> maps) {
//    vector<int> answer;
//    queue<pair<int, int>> q;
//    
//    int maxDays = 0;
//    
//    for(int i = 0; i < maps.size(); i++){
//        for(int j = 0; j < maps[0].length(); j++){
//            if(maps[i][j] != 'X'){
//                q.emplace(i, j);
//                
//                while(!q.empty()){
//                    int x = q.front().first;
//                    int y = q.front().second;
//                    q.pop();
//                    
//                    if(maps[x][y] != 'X'){
//                        // 예시 1번에서
//                        // 마지막 3 → 1 에서 1이 queue에 들어가고
//                        // 마지막 5 → 1 에서 1이 또 queue에 들어감
//                        // - 중복은 가능한데 먼저 들어간 1이 방문되고 나서 X로 바뀌면
//                        // - 두번째로 들어가있는 1이 X로 바뀐 상태이기 때문에 != 체크를 해줘야 함 
//                        maxDays += maps[x][y] - '0';
//                    
//                        // 방문
//                        maps[x][y] = 'X';
//                        
//                        // 상하좌우 연결 확인
//                        if(x-1 >= 0 && maps[x-1][y] != 'X'){
//                            q.emplace(x-1, y);
//                        }
//                        if(x+1 < maps.size() && maps[x+1][y] != 'X'){
//                            q.emplace(x+1, y);
//                        }
//                        if(y-1 >= 0 && maps[x][y-1] != 'X'){
//                            q.emplace(x, y-1);
//                        }
//                        if(y+1 < maps[0].length() && maps[x][y+1] != 'X'){
//                            q.emplace(x, y+1);
//                        }
//                    }
//                }
//                
//                if(maxDays != 0){
//                    answer.push_back(maxDays);
//                    maxDays = 0;
//                }
//            }   
//        }
//    }
//    
//    if(answer.empty())
//        return {-1};
//    
//    sort(answer.begin(), answer.end());
//    
//    return answer;
//}

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<vector<bool>> visited;

int dfs(int x, int y, vector<string>& maps) {
    int ret = maps[x][y] - '0';

    for(int k=0; k<4; k++) {
        int nextX = x+dx[k];
        int nextY = y+dy[k];
        if(0<= nextX && nextX<maps.size() && 0<=nextY && nextY<maps[0].size()) {
            if(!visited[nextX][nextY] && maps[nextX][nextY] != 'X') {
                visited[nextX][nextY] = true;
                ret += dfs(nextX, nextY, maps);
            }
        }
    }

    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    visited = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size(), false));

    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[0].size(); j++) {
            if(!visited[i][j] && maps[i][j] != 'X') {
                visited[i][j] = true;
                answer.push_back(dfs(i, j, maps));
            }
        }
    }

    if(answer.empty()) return {-1};

    sort(answer.begin(), answer.end());

    return answer;
}