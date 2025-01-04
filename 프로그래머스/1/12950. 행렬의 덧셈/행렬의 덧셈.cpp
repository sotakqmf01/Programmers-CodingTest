#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int a;
    int b;
    int c;
    
    vector<vector<int>> answer = arr1;
    
    int rows = arr1.size();
    int columns = arr1[0].size();
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    //vector<vector<int>> answer;
    
    //int rows = arr1.size();
    //int columns = arr1[0].size();
    
    //answer.reserve(rows);
    
    //for(int i = 0; i<rows; i++){
        //for(int j = 0; j<columns; j++){
            // answer는 vector<int>가 여러 개인 vector
            // => answer[n] 에는 vector<int>가 들어와야함
            // => 근데 현재 위에서 answer에 reserve로 capacity만 늘려줌
            // => 밑에 코드는 아무것도 없는 곳에 요소를 넣으려고 하니 segment 에러 발생
            // ==> 해결 1. 2번째 for문 들어오기 전에 answer[n] 에 vector<int>를 push_back()해서 vector 넣기
            // ==> 해결 2. resize로 size까지 늘려서 vector<int>를 넣어 주기
            //answer[i].push_back(arr1[i][j] + arr2[i][j]);
        //}
    //}
        
    return answer;
}