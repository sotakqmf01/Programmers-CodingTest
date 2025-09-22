#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CalculateCycle(int row, int col, int dir, vector<vector<vector<bool>>>& visited, vector<string>& grid){
    // 시계 방향(위/오른쪽/아래/왼쪽)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int cycleLength = 0;
    
    while(!visited[row][col][dir]){
        visited[row][col][dir] = true;
        cycleLength++;
        
        if(grid[row][col] == 'L')
            dir = (dir + 3) % 4;
        else if(grid[row][col] == 'R')
            dir = (dir + 1) % 4;
        
        row = (row + dx[dir] + (int)grid.size()) % (int)grid.size();
        col = (col + dy[dir] + (int)grid[0].size()) % (int)grid[0].size(); 
        
        // dir과 row(col)를 index에 맞게 래핑하는 수식은 같음
        // - row = (row + delta + (row + delta에 더했을 때 0보다 커질 수 있는 전체 크기(grid.size())의 배수)) % 전체 크기
        //  - L : dir = (dir + delta(-1) + 전체 크기(4)) % 4
        //  - R : dir = (dir + delta(+1) + 전체 크기(4)) % 4
        //    - R에서 전체 크기(4)는 분배 법칙에 의해 사라짐 => (dir + delta(+1)) % 4 
    }
    
    return cycleLength;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));
    
    for(int row = 0; row < grid.size(); row++){
        for(int col = 0; col < grid[0].size(); col++){
            for(int dir = 0; dir < 4; dir++){
                if(visited[row][col][dir])
                    continue;
                
                int cycleLength = CalculateCycle(row, col, dir, visited, grid);
                answer.push_back(cycleLength);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}