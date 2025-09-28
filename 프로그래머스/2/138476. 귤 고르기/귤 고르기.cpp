#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

//int solution(int k, vector<int> tangerine) {
//    int answer = 0;
//    int Count = 0;
//    map<int, int> m;
//    priority_queue<int> pq;
//    
//    //종류 별 개수
//    for(int i = 0; i<tangerine.size(); i++)
//    {
//        if(m.find(tangerine[i]) == m.end())
//        {
//            m.insert(make_pair(tangerine[i], 1));
//        }
//        else
//        {
//            m[tangerine[i]]++;
//        }
//    }
//    
//    // 종류 별 개수 정렬
//    for(pair<int, int> CountByType : m)
//    {
//        pq.push(CountByType.second);
//    }
//    
//    // k개를 고를 때 종류의 수를 가장 적게 만들기
//    while(!pq.empty())
//    {
//        Count += pq.top();
//        answer++;
//        
//        if(Count >= k)
//            return answer;
//        
//        pq.pop();
//    }
//    
//    return answer;
//}


// map + priority_queue
//int solution(int k, vector<int> tangerine){
//    int answer = 0;
//    
//    map<int, int> countBySize;
//    priority_queue<int> pqForCount;
//    
//    for(const int& size : tangerine){
//        countBySize[size]++;
//    }
//    
//    for(const pair<int, int>& count : countBySize){
//        pqForCount.push(count.second);
//    }
//    
//    int total = 0;
//    while(total < k){
//        total += pqForCount.top();
//        pqForCount.pop();
//        
//        answer++;
//    }
//    
//    return answer;
//}

// unordered_map + priority_queue
int solution(int k, vector<int> tangerine){
    int answer = 0;
    
    unordered_map<int, int> countBySize;
    priority_queue<int> pqForCount;
    
    for(const int& size : tangerine){
        countBySize[size]++;
    }
    
    for(const pair<int, int>& count : countBySize){
        pqForCount.push(count.second);
    }
    
    int total = 0;
    while(total < k){
        total += pqForCount.top();
        pqForCount.pop();
        
        answer++;
    }
    
    return answer;
}

// 다른 사람 풀이 : vector만 사용
// - max_element의 값에 따라 벡터의 크기가 달라짐
// - 사이즈가 1, 2, 1천만 이렇게 3개 있으면, coutBySize 배열의 크기는 1천만+1 => 때에 따라 비효율적일 수 있음
//int solution(int k, vector<int> tangerine){
//    int answer = 0;
//    
//    int maxSize = *max_element(tangerine.begin(), tangerine.end());
//    vector<int> countBySize(maxSize + 1, 0);
//    
//    for(const int& size : tangerine){
//        countBySize[size]++;
//    }
//    
//    sort(countBySize.begin(), countBySize.end(), greater<int>());
//    
//    int total = 0;
//    while(total < k){
//        total += countBySize[answer];
//        answer++;
//    }
//    
//    return answer;
//}