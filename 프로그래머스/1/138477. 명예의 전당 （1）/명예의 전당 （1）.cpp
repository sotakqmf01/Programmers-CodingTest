#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honor;
    
    for(int i = 0; i < score.size(); i++)
    {
        if(i < k)
        {
            honor.push_back(score[i]);
        }
        else{
            vector<int>::iterator it = min_element(honor.begin(), honor.end());
              
            if(*it < score[i])
            {
                //vector<int>::iterator it = find(honor.begin(), honor.end(), min_element(honor.begin(), honor.end()));
                *it = score[i];
            }                                   
        }
        answer.push_back(*min_element(honor.begin(), honor.end()));    
    }   
    return answer;
}