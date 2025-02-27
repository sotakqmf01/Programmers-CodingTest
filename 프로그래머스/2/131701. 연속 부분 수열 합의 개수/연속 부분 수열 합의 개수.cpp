#include <string>
#include <vector>
#include <set>

using namespace std;

// 다른 사람 풀이 + '질문하기'에 DP로 푼 풀이 보기
void SequenceSum(vector<int> elements, int n, set<int>& SeqSum)
{
    // 첫번째 요소부터 마지막 요소까지
    for(int i = 0; i < elements.size(); i++)
    {
        int sum = 0;
        
        // 각 요소에서 길이가 n인 연속 부분 수열의 합
        for(int j = 0; j < n; j++)
        {
            sum += elements[(i + j) % elements.size()];
        }
        
        SeqSum.insert(sum);
    }
}

//int solution(vector<int> elements) {
//    int answer = 0;
//    set<int> SeqSum;
//    
//    // 길이 1 ~ n
//    for(int i = 1; i <= elements.size(); i++)
//    {
//        SequenceSum(elements, i, SeqSum);
//    }
//    
//    // 길이가 1인 경우 DP[0][]에 넣을지 DP[1][]에 넣을 지에 따라 2차원 배열 Row가 (size() or size()+1)
//    // DP[i][j] = DP[i-1][j] + DP[1][(j+i-1) % elements.size()];
//    
//    return answer = SeqSum.size();
//}

int solution(vector<int> elements) {
    int answer = 0;
    set<int> SeqSum;
    int Size = elements.size();
    vector<vector<int>> DP(Size, vector<int>(Size, 0));
    
    for(int i = 0; i < Size; i++)
    {
        DP[0][i] = elements[i];  
        SeqSum.insert(DP[0][i]);
    }
    
    for(int i = 1; i < Size; i++)
    {
        for(int j = 0; j < Size; j++)
        {
            // 길이가 1인 경우 DP[0][]에 넣을지 DP[1][]에 넣을 지에 따라 2차원 배열 Row가 (size() or size()+1)
            DP[i][j] = DP[i-1][j] + DP[0][(j+i) % elements.size()];
            SeqSum.insert(DP[i][j]);
        }
    }

    return answer = SeqSum.size();
}