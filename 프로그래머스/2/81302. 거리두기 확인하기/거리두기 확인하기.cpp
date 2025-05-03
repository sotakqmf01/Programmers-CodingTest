#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

// 다른 사람 풀이 보기
//class Pos{
//public:
//    Pos(int initX, int initY) : x(initX), y(initY) {}
//    
//    int x = 0;
//    int y = 0;
//};

struct Pos{
    Pos(int initX, int initY) : x(initX), y(initY) {}
    
    int x = 0;
    int y = 0;
};

int ManDist(Pos p1, Pos p2){
    return abs(p2.x - p1.x) + abs(p2.y - p1.y);
}

int CheckSit(vector<Pos>& people, vector<string>& place){
    // 애초에 한 명인 경우나, 다 체크하고 한 명만 남은 상황이면 이미 앞서 체크를 했기 때문에 문제 없음
    while(people.size() > 1){
        // 제일 뒤에서부터 체크
        Pos currPos = people[people.size()-1];

        for(int i = people.size() - 2; i >= 0; i--){
            int dist = ManDist(currPos, people[i]);
            
            // 맨해튼 거리가 1인 경우는 거리두기 x
            if(dist == 1){
                return 0;
            }
            else if(dist == 2){
                // x의 차가 2 or y의 차가 2인 경우
                if(abs(people[i].x - currPos.x) == 2){
                    if(place[(people[i].x + currPos.x) / 2][currPos.y] != 'X')
                        return 0;
                }
                else if(abs(people[i].y - currPos.y) == 2){
                    if(place[currPos.x][(people[i].y + currPos.y) / 2] != 'X')
                        return 0;
                }
                // 대각선에 위치
                else{
                    if(!(place[currPos.x][people[i].y] == 'X' && place[people[i].x][currPos.y] == 'X'))
                        return 0;
                }
            }
        }

        people.erase(people.end()-1);
    }
    
    return 1;
}

//vector<int> solution(vector<vector<string>> places) {
//    vector<int> answer;
//    vector<Pos> people;
//    
//    for(vector<string>& place : places){
//        people.clear();
//        
//        // 각 방에 대한 사람들 위치 저장        
//        for(int i = 0; i<place.size(); i++){
//            for(int j = 0; j<5; j++){
//                if(place[i][j] == 'P'){
//                    people.emplace_back(i, j);
//                }
//            }
//        }
//        
//        answer.push_back(CheckSit(people, place));
//    }
//     
//    return answer;
//}

// BFS 사용 풀이
bool BFS(int x, int y, int dist, vector<string> place){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<Pos, int>> q;
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    
    q.emplace(Pos(x,y), dist);
    
    while(!q.empty()){
        int x = q.front().first.x;
        int y = q.front().first.y;
        int currDist = q.front().second;
        q.pop();
        
        if(currDist > 0 && place[x][y] == 'P')
            return false;
        if(currDist > 2)
            continue;
        if(visited[x][y] == true)
            continue;
        if(place[x][y] == 'X')
            continue;
        
        visited[x][y] = true;

        for(int i = 0; i<4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            int nextDist = currDist + 1;
            
            if(nextX < 0 || nextX > 4)
                continue;
            if(nextY < 0 || nextY > 4)
                continue;
            if(visited[nextX][nextY])
                continue;        
            
            if(nextDist <= 2)
                q.emplace(Pos(nextX, nextY), nextDist);
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
        
    for(vector<string>& place : places){
        bool bKeepDist = true;
        
        for(int i = 0; i<5; i++){
            for(int j = 0; j<5; j++){
                if(place[i][j] == 'P'){
                    bKeepDist = BFS(i, j, 0, place);
                    if(!bKeepDist)
                        break;
                }
            }
            
            if(!bKeepDist)
                break;
        }
        
        answer.push_back(bKeepDist ? 1 : 0);
    }
    
    return answer;
}


// 문제 접근 방법 1
// 1. 3중 for문으로 P와 X를 찾습니다.
//   1-1. 각 대기실마다 5x5의 Int배열을 만듭니다.
//   1-2. P는 P의 좌표와 해당 P의 상하좌우 좌표에 -1씩을 해줍니다.
//   1-3. X는 X의 좌표에 +10을 해줍니다. (10이라는 숫자에 별 의미는 없습니다.) 파티션 사방에 P가 있어도 파티션으로 막혀있다는 것을 표현하기위해 3이상의 숫자를 더하기만 해주면 됩니다.
// 2. 만약 2의 과정에서 생긴 Int배열에 -2이하의 숫자가 발견되면 거리두기를 안지켰다고 볼 수 있습니다. -> return 0
// 3. 없을경우 return 1

// 문제 접근 방법 2
// 각각의 원소를 기준으로 상하좌우 원소만 보고 풀면 되는데,
// 1) 자기 원소가 P일 때, 상하좌우 원소에 P가 없다.
// 2) 자기 원소가 O일 때, 상하좌우 원소에 P가 1개 이하이다.
// 이 2개의 조건을 모든 원소가 만족하면 되는 식으로 풀었습니다.
// 그런데 반례가 있는지 모르겠네요. 맨허튼 거리(L1-Distance)라서 그런가 대각선을 직접 고려하지 않아서 단순하긴 한데..
// - 대각선을 고려하지 않아도 되는 이유가 원소가 'O'인 경우 체크하기 때문