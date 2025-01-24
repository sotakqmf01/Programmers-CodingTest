#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> LottoRank = {6, 6, 5, 4, 3, 2, 1};
    int WinCount = 0;
    int ZeroCount = 0;
    
    for(int LottoNum : lottos)
    {
        if(LottoNum == 0)
        {
                ZeroCount++;
        }
        
        for(int WinNum : win_nums)
        {            
            if(LottoNum == WinNum)
            {
                WinCount++;
            }
        }
    }
    
    answer.push_back(LottoRank[WinCount+ZeroCount]);
    answer.push_back(LottoRank[WinCount]);
    
    return answer;
}