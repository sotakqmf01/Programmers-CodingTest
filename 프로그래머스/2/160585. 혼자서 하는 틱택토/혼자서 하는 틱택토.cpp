#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// DFS나 BFS로도 풀어보기

// 경우의 수
// 1. 선/후에 문제가 있는 경우
//   - 1.1. [O/X]의 개수 차이는 최대 1개
//   - 1.2. [X]는 [O]보다 많을 수 없음
// 2. 빙고가 되었는데도 게임을 이어가는 경우
//   - 2.1. [O]가 이겼을 때 : 정상적인 상황에선 [O]가 [X]보다 1개 많음(빙고가 되고도 진행되었더라도 빙고를 만드는 수를 마지막에 뒀다고 생각하면 나올 수는 있는 board임)
//     - => [O]가 [X]보다 작거나 같은 경우는 나올 수 없음
//     - ▶ 좀 더 생각할 게 ★ 선공은 빙고가 2개가 될 수도 있음 => ★★ 빙고 두 개 할 수 있음(두 빙고가 겹치는 수를 마지막에 두면 됨)
//       -               ★ [X]가 빙고가 되는 경우가 있을 수 없음
//   - 2.2. [X]가 이겼을 때 : [O]와 [X]의 개수가 같음
//     - => [O]와 [X]의 개수가 다른 경우는 나올 수 없음
//int FindBingo(char turn, const vector<string>& board){
//    int countOfBingo = 0;
//    
//    for(int i = 0; i < board.size(); i++){
//        // 가로
//        if(count(board[i].begin(), board[i].end(), turn) == board[i].length())
//            countOfBingo++;
//                
//        // 세로
//        int column = 0;
//        for(int j = 0; j < board.size(); j++){
//            if(board[j][i] == turn)
//                column++;
//        }
//        
//        if(column == board[i].length())
//            countOfBingo++;
//    }
//    
//    // 대각선
//    int rightDownDiagonal = 0;
//    int rightUpDiagonal = 0;
//    for(int i = 0; i < board.size(); i++){
//        if(board[i][i] == turn)
//            rightDownDiagonal++;
//        if(board[board.size() - 1 - i][i] == turn)
//            rightUpDiagonal++;
//    }
//    
//    if(rightDownDiagonal == board.size())
//        countOfBingo++;
//    if(rightUpDiagonal == board.size())
//        countOfBingo++;    
//    
//    return countOfBingo;
//}
//
//string FindWinner(const vector<string>& board){
//    string winner = "";
//    
//    int OBingo = FindBingo('O', board);
//    int XBingo = FindBingo('X', board);
//    if(OBingo == 1){
//        winner = "O";
//        
//        if(XBingo == 1)
//            winner = "WrongBoard";
//    }
//    else if(XBingo == 1)
//        winner = "X";
//    
//    return winner;
//}
//
//int solution(vector<string> board) {
//    bool bMaybePossible = true;
//    int countOfO = 0;
//    int countOfX = 0;
//    
//    for(const string& line : board){
//        countOfO += count(line.begin(), line.end(), 'O');
//        countOfX += count(line.begin(), line.end(), 'X');
//    }
//    
//    // 1. 선/후에 문제가 있는 경우
//    if(countOfO - countOfX > 1 || countOfO - countOfX < 0)
//        return 0;
//    
//    // 2. 빙고가 되었는데도 게임을 이어가는 경우
//    string winner = FindWinner(board);
//    if(winner == "O"){
//        if(countOfO <= countOfX)
//            return 0;
//    }else if(winner == "X"){
//        if(countOfO != countOfX)
//            return 0;
//    }else if(winner == "WrongBoard"){
//        return 0;
//    }
//    
//    return 1;
//}

// Gemini 풀이 (ChatGPT 풀이와 동일한 로직)
bool is_win(const vector<string>& board, char player) {
    // 가로 3줄
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // 세로 3줄
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // 대각선 2줄
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int solution(vector<string> board) {
    int o_count = 0;
    int x_count = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'O') {
                o_count++;
            } else if (board[i][j] == 'X') {
                x_count++;
            }
        }
    }

    bool o_win = is_win(board, 'O');
    bool x_win = is_win(board, 'X');

    // Case 1: X의 개수가 O의 개수보다 많거나, O의 개수가 X의 개수보다 2개 이상 많을 때
    if (x_count > o_count || o_count > x_count + 1) {
        return 0;
    }

    // Case 2: O, X가 모두 승리했을 때
    if (o_win && x_win) {
        return 0;
    }

    // Case 3: O가 승리했을 때 (O의 개수가 X의 개수와 같으면 안됨)
    if (o_win) {
        if (o_count == x_count) {
            return 0;
        }
    }

    // Case 4: X가 승리했을 때 (O의 개수가 X의 개수보다 하나 더 많으면 안됨)
    if (x_win) {
        if (o_count > x_count) {
            return 0;
        }
    }

    return 1;
}