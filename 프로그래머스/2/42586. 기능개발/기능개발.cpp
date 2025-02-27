#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Releases;
    int ReleaseCount = 0;
    int ReleaseDays = 0;
    
    // 각 작업의 배포까지 남은 일 수
    for(int i = 0; i < progresses.size(); i++)
    {
        Releases.push((int)(ceil((100-progresses[i]) / (float)speeds[i])));
    }
    
    // 어떤 배포일(A)을 기준으로 
    // A배포일보다 B배포일이 작으면 같이 배포
    // A배포일보다 B배포일이 크면 같이 배포하지 않음
    while(!Releases.empty())
    {
        // 이전 배포일보다 현재 배포일이 더 크면 기준을 더 큰 배포일로 변경
        if(Releases.front() > ReleaseDays)
        {
            ReleaseDays = Releases.front();
            if(ReleaseCount > 0)
            {
                // 배포하고 나면 개수 초기화화
                answer.push_back(ReleaseCount);
                ReleaseCount = 0;
            }
        }
 
        ReleaseCount++;
        Releases.pop();
        
        // 마지막 배포
        if(Releases.empty())
        {
            answer.push_back(ReleaseCount);
        }
    }
    
    return answer;
}