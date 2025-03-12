#include <string>
#include <vector>
#include <stack>

using namespace std;

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> stk;

    for(int i=0; i<numbers.size(); i++) {
        while(!stk.empty() && numbers[stk.top()] < numbers[i]) {
            answer[stk.top()] = numbers[i];
            stk.pop();
        }
        stk.push(i);
    }

    return answer;
}

//테스트 14 〉	통과 (169.88ms, 121MB)
//테스트 15 〉	통과 (362.42ms, 240MB)
//테스트 16 〉	통과 (367.68ms, 240MB)
//테스트 17 〉	통과 (362.63ms, 240MB)
//테스트 18 〉	통과 (337.65ms, 240MB)
//테스트 19 〉	통과 (351.61ms, 240MB)
//테스트 20 〉	통과 (346.53ms, 238MB)
//테스트 21 〉	통과 (394.68ms, 242MB)
//테스트 22 〉	통과 (265.23ms, 191MB)
//테스트 23 〉	통과 (348.83ms, 240MB)

// stack 사용 - DP와 비슷한 로직
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer(numbers.size(), -1); // answer는 뒷 큰수가 있는지 없는지 알 수 있음
//    stack<int> st;          // 스택에는 다음 수와 answer(다음 수의 뒷 큰수)를 넣음
//    
//    st.push(numbers[numbers.size()-1]);
//    
//    // 배열의 뒤에서부터 체크
//    for(int i = numbers.size() - 2; i >= 0; i--)
//    {        
//        while(!st.empty())
//        {
//            int num = st.top();
//            st.pop();
//            
//            if(numbers[i] < num)
//            {
//                answer[i] = num;
//                break;
//            }
//        }
//        
//        // 뒷 큰수가 있으면, 뒷 큰수까지 비교해볼 기회가 있어야함
//        // - {[6], 5, 4, 4, 4, 7} 인 경우
//        // - 뒷 큰수가 없으면 number[i]가 현재까지 가장 큰 수이니까 뒷 큰수는 몰라도 됨
//        if(answer[i] != -1)
//        {
//            st.push(answer[i]);    
//        }
//        st.push(numbers[i]);
//    }
//    
//    return answer;
//}

// DP - 이중 for문 - answer배열을 메모이제이션으로 사용
//vector<int> solution(vector<int> numbers) {
//    // answer는 뒷 큰수가 있는지 없는지 알 수 있음
//    vector<int> answer(numbers.size(), -1);
//    
//    // 배열의 뒤에서부터 체크
//    for(int i = numbers.size() - 2; i >= 0; i--)
//    {
//        for(int j = i + 1; j < numbers.size(); j++)
//        {
//            if(numbers[i] < numbers[j])
//            {
//                answer[i] = numbers[j];
//                break;
//            }
//            // numbers[i] >= numbers[j]인 경우
//            else    
//            {
//                // numbers[j]에 뒷 큰수가 없는 경우
//                if(answer[j] == -1)
//                {
//                    answer[i] = -1;
//                    break;
//                }
//                // numbers[j]에 뒷 큰수(A)가 있는 경우
//                // - numbers[i]가 뒷 큰수(A)보다 작은 경우는 numbers[i]의 뒷 큰수도 A가 됨
//                // - numbers[i]가 뒷 큰수(A)보다 작지 않은 경우는 뒷 큰수(A)의 뒷 큰수가 있는지 확인하러 가야함
//                //   - 두번째 for문이 해결해줌
//                else if(numbers[i] < answer[j])
//                {
//                    answer[i] = answer[j];
//                    break;
//                }
//            }
//        }
//    }
//  
//    return answer;
//}

// 가장 간단 - 이중 for문 => 시간 초과
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//    bool bFind = false;
//    
//    for(int i = 0; i < numbers.size(); i++)
//    {
//        bFind = false;
//        for(int j = i + 1; j < numbers.size(); j++)
//        {
//            if(numbers[i] < numbers[j])
//            {
//                bFind = true;
//                answer.push_back(numbers[j]);
//                break;
//            }
//        }
//        if(!bFind)
//        {
//            answer.push_back(-1);
//        }
//    }
//    
//    return answer;
//}