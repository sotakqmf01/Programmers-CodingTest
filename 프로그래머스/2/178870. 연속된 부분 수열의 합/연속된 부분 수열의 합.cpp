#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    queue<int> q;
    int firstIndex = 0;
    int index = 0;
    int length = sequence.size() + 1;  // sequence의 모든 원소를 더해야 k가 될 때를 생각
    int sum = 0;
    
    for(int& num : sequence){
        q.push(num);
        sum += num;
        
        if(sum < k){
            continue;
        }
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

//vector<int> solution(vector<int> sequence, int k)
//{
//    vector<int> answer;
//
//    int srt=0, end=0, sum=0;
//
//    for(int i=0; i<sequence.size(); i++)
//    {
//        end=i;
//        sum+=sequence[end];
//
//        while(sum>k)
//            sum-=sequence[srt++];
//
//        if(sum==k)
//            if(answer.empty() || end-srt < answer[1]-answer[0])
//                answer={srt, end};
//    }
//
//    return answer;
//}