#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// 모든 경우의 수 - DFS 백트래킹
// 백트래킹 : 모든 경우의 수를 탐색하는 과정에서, 조건문 등을 걸어 답이 절대로 될 수 없는 상황을 정의하고,
//           그러한 상황일 경우에는 탐색을 중지시킨 뒤 그 이전으로 돌아가서 다시 다른 경우를 탐색
int answer = 0;
vector<bool> Visited;           // 방문했는지

void DFS(int k, int depth, const vector<vector<int>>& dungeons){
    answer = max(answer, depth);
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(!Visited[i] && k >= dungeons[i][0])
        {
            Visited[i] = true;
            DFS(k - dungeons[i][1], depth + 1, dungeons);
            Visited[i] = false;     // 재귀 호출한 후에는 다른 경우의 수(순서)를 찾기 위해 방문하지 않은 상태로 변경
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    Visited = vector<bool>(dungeons.size(), false);
    
    DFS(k, 0, dungeons);
    
    return answer;
}

// 모든 경우의 수 - permutation
//int solution(int k, vector<vector<int>> dungeons){
//    int answer = 0;
//    vector<int> DungeonIndex(dungeons.size());
//    
//    for(int i = 0; i < DungeonIndex.size(); i++)
//    {
//        DungeonIndex[i] = i;
//    }
//    
//    do
//    {
//        int TempK = k;
//        int Count = 0;
//        
//        for(int i = 0; i < DungeonIndex.size(); i++)
//        {
//            if(TempK >= dungeons[DungeonIndex[i]][0])
//            {
//                TempK -= dungeons[DungeonIndex[i]][1];
//                Count++;
//            }
//        }
//        
//        answer = max(answer, Count);
//        
//    }while(next_permutation(DungeonIndex.begin(), DungeonIndex.end()));
//    
//    return answer;
//}

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