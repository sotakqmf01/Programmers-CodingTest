#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int Count = 0;
    map<int, int> m;
    priority_queue<int> pq;
    
    //종류 별 개수
    for(int i = 0; i<tangerine.size(); i++)
    {
        if(m.find(tangerine[i]) == m.end())
        {
            m.insert(make_pair(tangerine[i], 1));
        }
        else
        {
            m[tangerine[i]]++;
        }
    }
    
    // 종류 별 개수 정렬
    for(pair<int, int> CountByType : m)
    {
        cout << CountByType.second << endl;
        pq.push(CountByType.second);
    }
    
    while(!pq.empty())
    {
        Count += pq.top();
        answer++;
        
        if(Count >= k)
            return answer;
        
        pq.pop();
    }
    
    return answer;
}