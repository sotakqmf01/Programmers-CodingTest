#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int sectionIndex = 0;
    int painted = 0;
    
    for(int toBePainted : section)
    {
        if(painted < toBePainted)
        {
            painted = toBePainted + m - 1;
            answer++;
        }
    }
    
    return answer;
}