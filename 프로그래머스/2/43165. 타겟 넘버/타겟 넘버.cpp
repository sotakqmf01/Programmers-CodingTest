#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
    vector<int> combi(numbers.size(), 1);
    
    for(int i = 0; i <= numbers.size(); i++)
    {
        fill_n(combi.begin(), i, 0);
        
        do
        {
            sum = 0;
            
            for(int j = 0; j < numbers.size(); j++)
            {
                if(combi[j] == 0)
                {
                    sum -= numbers[j];
                }
                else
                {
                    sum += numbers[j];
                }
            }

            if(sum == target)
            {
                answer++;
            }
        }while(next_permutation(combi.begin(), combi.end()));
    }
    
    return answer;
}