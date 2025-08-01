#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    Pos() : x(0), y(0) {}
    Pos(int init_x, int init_y) : x(init_x), y(init_y) {}
    Pos(const Pos& other) : x(other.x), y(other.y) {}
    
    int x;
    int y;
};

// 특정 위치에서 특정 방향으로 미끄러졌을 때 도착하는 지점의 좌표 반환
// - direction : 0 = 상, 1 = 하, 2 = 좌, 3 = 우
Pos slide(const vector<string>& board, Pos currentPos, int direction){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    Pos dst(currentPos.x, currentPos.y);
        
    while((dst.x >= 0 && dst.x < board.size()) && (dst.y >= 0 && dst.y < board[0].length()) && (board[dst.x][dst.y] != 'D')){
        dst.x += dx[direction];
        dst.y += dy[direction];
    }
    
    dst.x -= dx[direction];
    dst.y -= dy[direction];
    
    return dst;
}
          
int solution(vector<string> board) {
    int answer = 0;
    // 방문 체크
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].length(), false));
    Pos start;
    
    queue<pair<Pos, int>> q;   // 상,하,좌,우 중 움직일 수 있는 방향으로 미끄러져 움직였을 때의 위치 저장
        
    // Robot의 위치 찾기
    for(int x = 0; x < board.size(); x++){
        size_t y = board[x].find('R');
        
        if(y != string::npos){
            start.x = x;
            start.y = (int)y;
            break;
        }
    }
    
    q.emplace(start, 0);
    visited[start.x][start.y] = true;
        
    while(!q.empty()){
        Pos curr = q.front().first;
        int move = q.front().second;
        q.pop();
        
        if(board[curr.x][curr.y] == 'G')
            return move;
                
        for(int i = 0; i < 4; i++){
            Pos next = slide(board, curr, i);
            if(!visited[next.x][next.y]){
                q.emplace(next, move + 1);
                // queue에 넣었을 때가 최단거리니까 그 이후로는 넣지 않기 위해 queue에 넣자말자 [방문] 체크
                // - 이렇게 하지 않고 queue에서 꺼낼 때 [방문] 체크를 하면
                // - queue에서 빼내기 전까지 같은 위치가 queue에 중복으로 들어갈 수 있음
                visited[next.x][next.y] = true;     
            }
        }
    }
    
    return -1;
}