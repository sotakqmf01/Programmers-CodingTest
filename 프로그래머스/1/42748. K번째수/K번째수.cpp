#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size = commands.size();
    
    for(int i = 0; i < size; i++)
    {
        int start = commands[i][0];
        int last = commands[i][1];
        int pick = commands[i][2];
        vector<int> temp = array;
        
        sort(temp.begin() + start - 1, temp.begin() + last);
        answer.push_back(temp[start + pick - 2]);
    }
    
    return answer;
}