#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 모든 경우의 수 - permutation
int solution(int k, vector<vector<int>> dungeons){
    int answer = 0;
    vector<int> DungeonIndex(dungeons.size());
    
    for(int i = 0; i < DungeonIndex.size(); i++)
    {
        DungeonIndex[i] = i;
    }
    
    do
    {
        int TempK = k;
        int Count = 0;
        
        for(int i = 0; i < DungeonIndex.size(); i++)
        {
            if(TempK >= dungeons[DungeonIndex[i]][0])
            {
                TempK -= dungeons[DungeonIndex[i]][1];
                Count++;
            }
        }
        
        answer = max(answer, Count);
        
    }while(next_permutation(DungeonIndex.begin(), DungeonIndex.end()));
    
    return answer;
}

// (필요 피로도 - 소모 피로도) 값을 기준으로 내림차순
//bool Compare(const vector<int>& a, const vector<int>& b)
//{
//    if((a[0] - a[1]) > (b[0] - b[1]))
//        return true;
//    else if((a[0] - a[1]) < (b[0] - b[1]))
//        return false;
//    else
//	    return ; 
//}

//int solution(int k, vector<vector<int>> dungeons) {
//    int answer = 0;
//    
//    sort(dungeons.begin(), dungeons.end(), Compare);
//    
//    // 반례
//    // j = 78
//    // dungeons = [[78, 18], [70, 11], [67, 9], [60, 8], [59, 2], [57, 54]]
//    // ans = 4 => [70, 11], [60, 8], [59, 2], [57, 54] 순서
//    
//    for(int i = 0; i < dungeons.size(); i++)
//    {
//        if(k >= dungeons[i][0])
//        {
//            k -= dungeons[i][1];
//            answer++;
//        }
//    }
//    
//    return answer;
//}