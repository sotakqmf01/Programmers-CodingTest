#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

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
        
        if(mainBox == order[orderIndex])
        {
            mainBelt.pop();
            answer++;
            orderIndex++;
        }
        else if(subBox == order[orderIndex])
        {
            subBelt.pop();
            answer++;
            orderIndex++;
        }
        else
        {
            if(!mainBelt.empty())
            {
                subBelt.push(mainBox);
                mainBelt.pop();
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}