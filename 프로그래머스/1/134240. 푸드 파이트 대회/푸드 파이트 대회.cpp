#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string opposite = "";
    int size = food.size();
    
    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < food[i]/2; j++)
        {
            answer += to_string(i);
            opposite += to_string(i);
        }
    }
    
    reverse(opposite.begin(), opposite.end());
    
    answer += '0';
    answer += opposite;
    
    return answer;
}