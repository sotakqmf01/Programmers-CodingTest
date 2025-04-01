#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 뭔가 뒤 큰 수 문제가 생각이 나네
// https://school.programmers.co.kr/learn/courses/30/lessons/154539
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

// 다른 사람 풀이임
// i ~ i+k(총 k개) 내의 최댓값의 위치를 찾고, 그 위치까지 거리를 구해서 k에서 빼고 해당 위치까지의 숫자 삭제
// ex) 12345, 3
//  - idx [0,3) => 1,2,3 중 3이 최대
//  - 3까지 거리는 2 => k = k - 2 = 1;
//  - 해당 위치까지 숫자 지우기 => 345
//string solution(string number, int k) {
//    for (int i = 0; i < number.size() - k; ++i) {
//        auto iter = std::max_element(number.begin() + i, number.begin() + i + k + 1);
//        if (iter != number.begin() + i) {
//            k = k - std::distance(number.begin() + i, iter);
//            number.erase(number.begin() + i, iter);
//        }
//    }
//  - 이후 k가 남아있으면(내림차순인 경우), 오른쪽에서 k개 자름
//    number.erase(number.end() - k, number.end());
//    return number;
//}