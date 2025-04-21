#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    // 굳이 queue를 사용하지 않아도 될 것 같았는데,
    // 뭔가 로직을 생각하고 나니 선입선출의 모양이라 사용
    queue<int> q;
    int firstIndex = 0;
    int index = 0;
    int length = sequence.size() + 1;  // sequence의 모든 원소를 더해야 k가 될 때를 생각
    int sum = 0;
    
    for(int& num : sequence){
        q.push(num);
        sum += num;
        
        // if랑 else 부분은 필요 없는 코드
        // else if 부분을 그냥 if로 해도 될 듯
        if(sum < k){
            continue;
        }
        // 합이 k보다 크면 작아질 때까지 앞 요소 빼기
        else if(sum > k){
            while(sum > k)
            {
                int subNum = q.front();
                q.pop();
                
                sum -= subNum;
                index++;
            }
        }
        else{}
        
        if(sum == k){
            // 부분 수열의 길이 비교
            if(length > q.size())
            {
                firstIndex = index;
                length = q.size();
            }
        }
    }
    
    answer.push_back(firstIndex);
    answer.push_back(firstIndex + length - 1);  // secondIndex = firstIndex + length - 1;
    
    return answer;
}

// 다른 사람 풀이 - 투포인터
//vector<int> solution(vector<int> sequence, int k)
//{
//    vector<int> answer;
//
//    int start=0, end=0, sum=0;
//
//    for(int i=0; i<sequence.size(); i++)
//    {
//        end=i;
//        sum+=sequence[end];
//
//        while(sum>k)
//            sum-=sequence[start++];
//
//        if(sum==k)
//            if(answer.empty() || end-start < answer[1]-answer[0])
//                answer={start, end};
//    }
//
//    return answer;
//}