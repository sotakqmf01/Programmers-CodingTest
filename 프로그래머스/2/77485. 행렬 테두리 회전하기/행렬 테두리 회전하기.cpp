#include <string>
#include <vector>
#include <limits.h>

using namespace std;

//enum DIR{
//    RIGHT = 0,
//    DOWN = 1,
//    LEFT = 2,
//    UP = 3
//};
//
//bool CanGo(int x, int y, vector<int>& query){
//    if(x < query[0] - 1 || x >= query[2])
//        return false;
//    if(y < query[1] - 1 || y >= query[3])
//        return false;
//    return true;
//}
//
//int Rotation(vector<int>& query, vector<vector<int>>& matrix){
//    int x = query[0] - 1;
//    int y = query[1] - 1;
//    int baseX = x;
//    int baseY = y;
//    int min = INT_MAX;
//    int dir = RIGHT;
//	int dx[] = { 0, 1, 0, -1 };
//	int dy[] = { 1, 0, -1, 0 };
//    
//    int totalRotationCount = 2*(query[3]-query[1]+1) + 2*(query[2]-query[0]-1);
//    int count = 0;
//    while(count < totalRotationCount){
//        int nextX = x + dx[dir];
//        int nextY = y + dy[dir];
//        
//        if(CanGo(nextX, nextY, query)){
//            swap(matrix[baseX][baseY], matrix[nextX][nextY]);
//            x = nextX;
//            y = nextY;
//            count++;
//            
//            if(min > matrix[x][y])
//                min = matrix[x][y];
//        }
//        else{
//            dir = (dir + 1) % 4;
//        }
//    }
//    
//    return min;
//}
//
//vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
//    vector<int> answer;
//    vector<vector<int>> matrix(rows, vector<int>(columns));
//        
//    for(int i = 0; i < rows; i++){
//        for(int j = 0; j < columns; j++){
//            matrix[i][j] = i*columns + (j+1);
//        }
//    }
//    
//    for(vector<int>& query : queries){
//        answer.push_back(Rotation(query, matrix));
//    }
//    
//    return answer;
//}

int rotate(vector<vector<int>>& matrix, pair<int, int> query_start, pair<int, int> query_end)
{
    int first = matrix[query_start.first - 1][query_start.second - 1];
    int min_val = first;

    for (int i = query_start.first; i < query_end.first; i++)
    {
        matrix[i - 1][query_start.second - 1] = matrix[i][query_start.second - 1];

        min_val = min(min_val, matrix[i - 1][query_start.second - 1]);
    }

    for (int i = query_start.second; i < query_end.second; i++)
    {
        matrix[query_end.first - 1][i - 1] = matrix[query_end.first - 1][i];

        min_val = min(min_val, matrix[query_end.first - 1][i - 1]);
    }

    for (int i = query_end.first - 2; i >= query_start.first - 1; i--)
    {
        matrix[i + 1][query_end.second - 1] = matrix[i][query_end.second - 1];

        min_val = min(min_val, matrix[i + 1][query_end.second - 1]);
    }

    for (int i = query_end.second - 2; i > query_start.second - 1; i--)
    {
        matrix[query_start.first - 1][i + 1] = matrix[query_start.first - 1][i];

        min_val = min(min_val, matrix[query_start.first - 1][i + 1]);
    }

    matrix[query_start.first - 1][query_start.second] = first;

    return min_val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns));

    int num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = num++;
        }
    }

    for (auto query : queries)
    {
        answer.push_back(rotate(matrix, { query[0], query[1] }, { query[2], query[3] }));
    }

    return answer;
}