#include <string>
#include <vector>

using namespace std;

int zeroNum = 0;
int oneNum = 0;

// [rowStart, rowEnd)와 [colStart, colEnd) 영역을 처리
void Division(vector<vector<int>>& arr, int rowStart, int rowEnd, int colStart, int colEnd)
{
    if(rowEnd - 1 < rowStart || colEnd - 1 < colStart)
    {
        return;
    }
    
    int pivot = arr[rowStart][colStart];
    bool isAllSame = true;
    
    for(int i = rowStart; i < rowEnd; i++)
    {
        for(int j = colStart; j < colEnd; j++)
        {
            if(pivot != arr[i][j])
            {
                isAllSame = false;
                break;
            }
        }
        if(!isAllSame)
        {
            break;
        }
    }
    
    if(isAllSame)
    {
        pivot ? oneNum++ : zeroNum++;
    }
    else{
        // 인덱스 범위 지정 잘 해야함(그냥 rowEnd/2 이런 식으로 하지말고)
        int rowMid = (rowStart + rowEnd) / 2;
        int colMid = (colStart + colEnd) / 2;
        
        // UpLeft
        Division(arr, rowStart, rowMid, colStart, colMid);
        // UpRight
        Division(arr, rowStart, rowMid, colMid, colEnd);
        // DownLeft
        Division(arr, rowMid, rowEnd, colStart, colMid);
        // DownRight
        Division(arr, rowMid, rowEnd,  colMid, colEnd);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    Division(arr, 0, arr.size(), 0, arr.size());
    
    answer.push_back(zeroNum);
    answer.push_back(oneNum);
    
    return answer;
}