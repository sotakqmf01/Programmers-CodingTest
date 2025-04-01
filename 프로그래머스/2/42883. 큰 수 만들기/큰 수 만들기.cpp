#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> compareStack;

    for(int i = 0; i < number.length(); i++)
    {
        int num = number[i] - '0';
        
        if(compareStack.empty() || num <= compareStack.top())
        {
            compareStack.push(num);
        }
        // 뒤의 수가 더 큰 경우 앞에서 본 작은 값을 지움
        else
        {
            while(k > 0 && !compareStack.empty())
            {
                if(num > compareStack.top())
                {
                    compareStack.pop();
                    k--;
                }
                else
                {
                    // 스택 : [4][1], 현재 2 => 1을 pop()하고 나면 4랑 비교될 때 while문 탈출
                    break;
                }
            }
            
            compareStack.push(num);
        }
    }
    
    while(!compareStack.empty())
    {
        answer += compareStack.top() + '0';
        compareStack.pop();
    }
    
    reverse(answer.begin(), answer.end());

    // 987654321과 같은 경우 compareStack에 그대로 다 들어감(k가 하나도 안 줄어듦)
    // => 오른쪽에서 k개 자름
    answer = answer.substr(0, answer.length() - k);
    
    return answer;
}