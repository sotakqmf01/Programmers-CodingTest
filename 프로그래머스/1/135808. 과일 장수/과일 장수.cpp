#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int index = m-1;
    
    sort(score.begin(), score.end(), greater<int>());
    
    for(int s : score)
    {
        if(index <= score.size())
        {
            answer += score[index] * m;
            index += m;
        }
    }
    
    return answer;
}