#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    // 내림차순 정렬
    sort(citations.rbegin(), citations.rend());
    
    // for문의 i가 커짐에 따라
    // - [내림차순] 정렬한 citations을 0번 n까지 => 점점 작아지면서
    // - (h = i + 1) => 점점 커지면서
    // citations[i] = h 가 되는 이 부분을 경계로 
    // - i + 1 <= a 인 경우에는 h에 포함되고
    // - i + 1 > a 인 경우에는 h에 포함되지 않는다
    // ex) {7,6,5,4,3,2,1}로 보면 이해가 잘됨
    // ex) {6,5,4,3,2,1} / {3,1,1,1}로 보면 이해가 잘 안될 수도 있는데 
    //     - 문제 설명에 "나머지 논문이 h번 [이하] 인용"이라고 되어있기 때문에 
    //     - h번 인용된 논문이 편 수에 포함되지 않을 수도 있다
    for(int i = 0; i < citations.size(); i++)
    {
        if(citations[i] >= i + 1)
        {
            answer++;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}