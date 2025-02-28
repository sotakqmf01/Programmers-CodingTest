#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int Count = 0;  // 실행한 프로세스 수
    int CurrentProcessIndex = max_element(priorities.begin(), priorities.end()) - priorities.begin();
    int NextProcessIndex;
    int Priority;
    
    if(CurrentProcessIndex == priorities.size() - 1)
    {
        NextProcessIndex = 0;
    }
    else
    {
        NextProcessIndex = CurrentProcessIndex + 1;
    }
    
    //반례입니다.
    //입력값 〉 [2, 3, 1, 2], 3
    //기댓값 〉 2
    while(Count < priorities.size())
    {
        Count++;
        priorities[CurrentProcessIndex] = -1;
        
        if(CurrentProcessIndex == location)
        {
            return Count;
        }
        
        // 현재 인덱스 기준[]으로 이전/이후() 큐에 있는 것 비교하기 위해
        // {(2,2,3,7,3),[9],(2,3,6)} => 이전 큐에 있는 7을 다음에 실행
        // {(2,2,3,6,3),[9],(2,3,6)} => 이후 큐에 있는 6을 다음에 실행(웬만하면 대기 큐에서 순서대로 가져와야함)
        int BeforeHighestPriority = *max_element(priorities.begin(), priorities.begin() + CurrentProcessIndex);
        int AfterHighestPriority = *max_element(priorities.begin() + CurrentProcessIndex, priorities.end());
        if(BeforeHighestPriority > AfterHighestPriority)
        {
            CurrentProcessIndex = max_element(priorities.begin(), priorities.begin() + CurrentProcessIndex) - priorities.begin();
        }
        else
        {
            // 웬만하면 대기 큐에서 순서대로 가져와야함
            if(AfterHighestPriority > priorities[NextProcessIndex])
            {
                CurrentProcessIndex = max_element(priorities.begin() + CurrentProcessIndex, priorities.end()) - priorities.begin();
            }
            else
            {
                // else 부분이 필요 없나?
                CurrentProcessIndex = NextProcessIndex;
            }
        }

        if(CurrentProcessIndex == priorities.size() - 1)
        {
            NextProcessIndex = 0;
        }
        else
        {
            NextProcessIndex = CurrentProcessIndex + 1;
        }
    }
    
    return Count;
}