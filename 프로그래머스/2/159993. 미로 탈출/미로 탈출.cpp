#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    Pos() {}
    Pos(int initX, int initY) : x(initX), y(initY) {}
    
    bool operator==(const Pos& other) {
	    return y == other.y && x == other.x;
    }
    
    int x = 0;
    int y = 0;
};

bool CanGo(int x, int y, const vector<string>& maps){
    if(x < 0 || x >= maps.size())
        return false;
    if(y < 0 || y >= maps[0].length())
        return false;
    if(maps[x][y] == 'X')
        return false;
    
    return true;
}

int BFS(Pos& Src, Pos& Dst, const vector<string>& maps){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<Pos, int>> q;  // 특정 Pos와 Src에서 이 Pos까지의 거리를 쌍으로 저장
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    
    q.emplace(Src, 0);
    visited[Src.x][Src.y] = true;
    
    while(!q.empty()){
        Pos CurrentPos = q.front().first;
        int CurrentDistance = q.front().second;
        q.pop();
        
        if(CurrentPos == Dst)
        {
            return CurrentDistance;
        }
                
        for(int i = 0; i < 4; i++){
            int NextX = CurrentPos.x + dx[i];
            int NextY = CurrentPos.y + dy[i];
            int NextDistance = CurrentDistance + 1;
            
            if(CanGo(NextX, NextY, maps)){
                if(!visited[NextX][NextY]){
                    q.emplace(Pos(NextX, NextY), NextDistance);
                    
                    // queue에 넣고 바로 체크를 해야 queue에 중복으로 들어가지 않음
                    // 만약 바로 체크 안할거면, 위에서 visited가 true이면 continue하도록 해야함
                    visited[NextX][NextY] = true;   
                }
            }
        }
        
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int StartToLever = 0;
    int LeverToEnd = 0;
    Pos Start;
    Pos Lever;
    Pos End;
    
    // 시작, 레버, 문(출구) 찾기
    for(int x = 0; x < maps.size(); x++)   {
        for(int y = 0; y < maps[x].length(); y++){
            if(maps[x][y] == 'S')
                Start = Pos(x, y);
            if(maps[x][y] == 'L')
                Lever = Pos(x, y);
            if(maps[x][y] == 'E')
                End = Pos(x, y);
        }
    }
    
    // [시작 -> 레버] 최단거리와 [레버 -> 문] 최단거리 구하기
    StartToLever = BFS(Start, Lever, maps);
    LeverToEnd = BFS(Lever, End, maps);
    if(StartToLever == -1 || LeverToEnd == -1){
        return -1;
    }
    
    return StartToLever + LeverToEnd;
}