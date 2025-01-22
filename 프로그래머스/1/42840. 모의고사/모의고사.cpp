#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> supo1 = {1,2,3,4,5};
    vector<int> supo2 = {2,1,2,3,2,4,2,5};
    vector<int> supo3 = {3,3,1,1,2,2,4,4,5,5};
    
   vector<int> scores(3, 0);
    
    int answerIndex = 0;
    
    for(int answer : answers)
    {
        if(supo1[answerIndex % supo1.size()] == answer)
            scores[0]++;
        if(supo2[answerIndex % supo2.size()] == answer)
            scores[1]++;
        if(supo3[answerIndex % supo3.size()] == answer)
            scores[2]++;
        
        answerIndex++;
    }
    
    int maxScore = *max_element(scores.begin(), scores.end());
    
    int index = 1;
    for(int score : scores)
    {
        if(score == maxScore)
            answer.push_back(index);
        
        index++;
    }
    
    return answer;
}