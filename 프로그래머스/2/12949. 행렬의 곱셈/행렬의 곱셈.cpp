#include <string>
#include <vector>

using namespace std;

//vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
//    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
//    
//    // [3]x(4) 행렬 * (4)x{2} 행렬 => [3]x{2} 행렬
//    // 두 행렬의 곱을 계산할 때 한 좌표는 (4)번의 곱셈 계산이 필요
//    // 결과 행렬의 x => [3]
//    for(int i = 0; i < arr1.size(); i++)
//    {
//        // 결과 행렬의 y => {2}
//        for(int j = 0; j < arr2[0].size(); j++)
//        {
//            // 결과 행렬을 계산 => (4)
//            for(int k = 0; k < arr1[0].size(); k++)
//            {
//                answer[i][j] += arr1[i][k] * arr2[k][j];
//            }
//        }
//    }
//    
//    return answer;
//}


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2){
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    int rows = arr1.size();
    int columns = arr2[0].size();
    
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            for(int i = 0; i < arr1[0].size(); i++){
                answer[row][column] += arr1[row][i] * arr2[i][column];
            }
        }
    }
    
    return answer;
}

