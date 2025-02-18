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

int solution(vector<int> elements) {
    int answer = 0;
    set<int> SeqSum;
    
    // 길이 1 ~ n
    for(int i = 1; i <= elements.size(); i++)
    {
        SequenceSum(elements, i, SeqSum);
    }
    
    // DP[i][j] = DP[i-1][j] + DP[1][(j+i-1) % elements.size()];
    
    return answer = SeqSum.size();
}