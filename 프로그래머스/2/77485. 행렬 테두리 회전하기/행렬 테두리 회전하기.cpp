#include <string>
#include <vector>
#include <limits.h>

using namespace std;

enum DIR{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3
};

bool CanGo(int x, int y, vector<int>& query){
    if(x < query[0] - 1 || x >= query[2])
        return false;
    if(y < query[1] - 1 || y >= query[3])
        return false;
    return true;
}

int Rotation(vector<int>& query, vector<vector<int>>& matrix){
    int x = query[0] - 1;
    int y = query[1] - 1;
    int baseX = x;
    int baseY = y;
    int min = INT_MAX;
    int dir = RIGHT;
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
    
    int totalRotationCount = 2*(query[3]-query[1]+1) + 2*(query[2]-query[0]-1);
    int count = 0;
    while(count < totalRotationCount){
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        
        if(CanGo(nextX, nextY, query)){
            swap(matrix[baseX][baseY], matrix[nextX][nextY]);
            x = nextX;
            y = nextY;
            count++;
            
            if(min > matrix[x][y])
                min = matrix[x][y];
        }
        else{
            dir = (dir + 1) % 4;
        }
    }
    
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix;
    matrix.resize(rows);
        
    for(int i = 0; i < rows; i++){
        matrix[i].resize(columns);
        for(int j = 0; j < columns; j++){
            matrix[i][j] = i*columns + (j+1);
        }
    }
    
    for(vector<int>& query : queries){
        answer.push_back(Rotation(query, matrix));
    }
    
    return answer;
}