#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int Count = 0;  // 실행한 프로세스 수
    int CurrentProcessIndex = max_element(priorities.begin(), priorities.end()) - priorities.begin();
    
    // 반례입니다.
    // 입력값 〉 [2, 3, 1, 2], 3
    // 기댓값 〉 2
    // => (웬만하면 대기 큐에서 순서대로 가져와야함) - 순서대로 가져오는건 당연함 큐에 들어있는 거니까
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
        // {(2,2,3,6,3),[9],(2,3,6)} => 이후 큐에 있는 6을 다음에 실행
        int BeforeHighestPriority = *max_element(priorities.begin(), priorities.begin() + CurrentProcessIndex);
        int AfterHighestPriority = *max_element(priorities.begin() + CurrentProcessIndex, priorities.end());
        if(BeforeHighestPriority > AfterHighestPriority)
        {
            CurrentProcessIndex = max_element(priorities.begin(), priorities.begin() + CurrentProcessIndex) - priorities.begin();
        }
        else
        {
            // 웬만하면 대기 큐에서 순서대로 가져와야함
             CurrentProcessIndex = max_element(priorities.begin() + CurrentProcessIndex, priorities.end()) - priorities.begin();
        }
    }
    
    return Count;
}

//int solution(vector<int> priorities, int location) {
//    // 반례입니다.
//    // 입력값 〉 [2, 3, 1, 2], 3
//    // 기댓값 〉 2
//    // => (웬만하면 대기 큐에서 순서대로 가져와야함)
//    int Count = 0;  // 실행한 프로세스 수
//    int CurrentProcessIndex = max_element(priorities.begin(), priorities.end()) - priorities.begin();
//    int NextProcessIndex;
//    
//    if(CurrentProcessIndex == priorities.size() - 1)
//    {
//        NextProcessIndex = 0;
//    }
//    else
//    {
//        NextProcessIndex = CurrentProcessIndex + 1;
//    }
//    
//    while(Count < priorities.size())
//    {
//        Count++;
//        // 실행한 프로세스는 우선순위 -1로 설정해서 다음 프로세스 찾을 때 문제가 없도록 함
//        priorities[CurrentProcessIndex] = -1;
//        
//        if(CurrentProcessIndex == location)
//        {
//            return Count;
//        }
//        
//        // 다음으로 높은 우선순위를 갖는 프로세스 찾기
//        // {(1,1),[9],(1,1,1)} 이라면 9(2번 프로세스)가 실행되고나면, 다음에 1(3번 프로세스)가 실행되어야 함
//        // ▶ 여기서 순서대로해야하는걸 생각했는데 예외는 생각을 못했네...
//        if(*max_element(priorities.begin(), priorities.end()) > priorities[NextProcessIndex])
//        {
//            CurrentProcessIndex = max_element(priorities.begin(), priorities.end()) - priorities.begin();
//        }
//        else
//        {
//            CurrentProcessIndex = NextProcessIndex;
//        }
//        
//        // 우선 순위가 높은 프로세스의 Index의 다음 Index
//        NextProcessIndex = (CurrentProcessIndex + 1) % priorites.size() ;
//    }
//    
//    return Count;
//}
