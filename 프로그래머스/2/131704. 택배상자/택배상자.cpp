#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 코드 길이를 좀 더 줄일 수 있는 법 생각해보기
int solution(vector<int> order) {
    int answer = 0;
    queue<int> mainBelt;
    stack<int> subBelt;
    
    for(int i = 1; i <= order.size(); i++)
    {
        mainBelt.push(i);
    }
    
    int orderIndex = 0;
    while(!mainBelt.empty() || !subBelt.empty())
    {
        int mainBox = 0;
        int subBox = 0;
        
        if(!mainBelt.empty())
        {
            mainBox = mainBelt.front();
        }
        if(!subBelt.empty())
        {
            subBox = subBelt.top();
        }
        
        // 메인 벨트의 상자와 배달 순서 상자 비교
        if(mainBox == order[orderIndex])
        {
            mainBelt.pop();
            answer++;
            orderIndex++;
        }
        // 보조 벨트의 상자와 배달 순서 상자 비교
        else if(subBox == order[orderIndex])
        {
            subBelt.pop();
            answer++;
            orderIndex++;
        }
        else
        {
            // 메인 벨트의 상자를 보조 벨트로 옮기기
            if(!mainBelt.empty())
            {
                subBelt.push(mainBox);
                mainBelt.pop();
            }
            // 처리할 수 있는 상자가 없는 경우
            else
            {
                break;
            }
        }
    }
    
    return answer;
}