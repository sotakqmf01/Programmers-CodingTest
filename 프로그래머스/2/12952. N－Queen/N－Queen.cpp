#include <string>
#include <vector>

using namespace std;

// 1. 퀸은 각 행에 하나씩 배치
//   - 첫번째 퀸을 0번 행의 0 ~ n-1 열에 배치하는 걸 dfs의 시작
// 2. 각 행에서 현재 위치에 퀸을 배치할 수 있는 지에 대한 유효성 검사를 함
//   - 백트래킹할 것까지 생각해서 로직을 생각해야함
//     - Gemini : 첫 행부터 이전 행까지에 대해 <같은 열>에 있는지 + <대각선 상>에 있는지 확인
//     - ChatGPT : 열, 대각선에 대해 퀸이 존재하는지를 저장하고, 이를 통해 유효성 체크
// 3. 퀸을 모두 배치한 경우 개수 늘리기

// Gemini 버전
//void dfs(int row, int n, vector<int>& col_Place, int& count){
//    // 모든 퀸을 배치한 경우
//    if(row == n){
//        count++;
//        return;
//    }
//    
//    // 현재 행의 모든 열에 퀸 배치
//    for(int col = 0; col < n; col++){
//        bool canPlace = true;
//        
//        // 첫 행부터 이전 행까지에 대해 <같은 열>에 있는지 + <대각선 상>에 있는지 확인
//        for(int prevRow = 0; prevRow < row; prevRow++){
//            int prevCol = col_Place[prevRow];
//            
//            if(prevCol == col || abs(prevRow - row) == abs(prevCol - col)){
//                canPlace = false;
//                break;
//            }            
//        }
//        
//        if(canPlace){
//            col_Place[row] = col;
//            dfs(row + 1, n, col_Place, count);
//        }
//    }
//}
//
//int solution(int n) {
//    int answer = 0;
//    vector<int> col_Place(n, -1);   // 각 row에 배치된 퀸의 column 저장
//    
//    dfs(0, n, col_Place, answer);
//    
//    return answer;
//}


// ChatGPT 버전
void dfs(int row, int n, vector<bool>& column, vector<bool>& diagonal_right, vector<bool>& diagonal_left, int& count){
    if(row == n){
        count++;
        return;
    }
    
    // 현재 행의 모든 열에 대해 퀸 배치
    for(int col = 0; col < n; col++){
        if(!(column[col] || diagonal_right[row - col + n - 1] || diagonal_left[row + col])){
            // 배치
            column[col] = diagonal_right[row - col + n - 1] = diagonal_left[row + col] = true;
            dfs(row + 1, n, column, diagonal_right, diagonal_left, count);
            
            // 백트래킹
            column[col] = diagonal_right[row - col + n - 1] = diagonal_left[row + col] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<bool> column(n, false);
    // n*n 배열에서 생길 수 있는 대각선의 개수는 2n + 1개
    vector<bool> diagonal_right(2*n + 1, false);    // row - col
    vector<bool> diagonal_left(2*n + 1, false);     // row + col
    
    dfs(0, n, column, diagonal_right, diagonal_left, answer);
    
    return answer;
}



// 두 코드에서 다른 점이 ChatGPT는 백트래킹을 위한 코드가 있음