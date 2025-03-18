#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long number : numbers)
    {
        long long check = 1;
        long long prevCheck = 0;
        while(1)
        {
            if(!(number & check))
            {
                number = number | check;
                if(prevCheck != 0)
                {
                    number = number - prevCheck;
                }
                answer.push_back(number);
                break;
            }
            else
            {
                prevCheck = check;
            }
            
            check = check << 1;
        }
    }
    
    return answer;
}