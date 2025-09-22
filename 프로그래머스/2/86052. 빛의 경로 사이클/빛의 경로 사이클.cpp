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