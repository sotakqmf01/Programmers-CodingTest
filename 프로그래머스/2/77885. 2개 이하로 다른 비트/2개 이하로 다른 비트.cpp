#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long number : numbers)
    {
        long long check = 1;
        long long prevCheck = 0;
        
        // f(7) = 11 예제를 보면 규칙을 찾을 수 있음
        // => 첫번째 비트(제일 오른쪽 비트)부터 비교했을 때 0이면 그냥 바꾸면 됨
        // ==> 근데 1이 나오고 0(01, 0111)이 나오는 경우에는 0을 1로 바꾸고 0 바로 뒤에 있는 1을 0으로 바꿔야함
        while(1)
        {
            // 해당 자리 비트가 0이면
            if(!(number & check))
            {
                // 0을 1로 바꾸고
                number = number + check;
                // 0 뒤에 1이였으면, 1을 0으로
                if(prevCheck != 0)
                {
                    number = number - prevCheck;
                }
                answer.push_back(number);
                break;
            }
            // 해당 자리 비트가 1이면 그 위치를 기억
            else
            {
                prevCheck = check;
            }
            
            // 비트 자리 이동
            check = check << 1;
        }
    }
    
    return answer;
}