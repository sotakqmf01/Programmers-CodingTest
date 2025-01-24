#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> nephew = {"aya", "ye", "woo", "ma"};
    
    for(string babble : babbling)
    {
        int NextStringIndex = 0;
        bool isPossible = true;
        int PrevNephewIndex = -1;
        
        while(NextStringIndex < babble.length() && isPossible)
        {
            for(int i = 0; i<nephew.size(); i++)
            {
                if(babble.compare(NextStringIndex, nephew[i].length(), nephew[i], 0, nephew[i].length()) == 0)
                {
                    if(PrevNephewIndex == i)
                    {
                        isPossible = false;
                    }
                    else
                    {
                        NextStringIndex += nephew[i].length();
                        PrevNephewIndex = i;
                        isPossible = true;
                        break;
                    }
                }
                else
                {
                    isPossible = false;
                }
            }
        }
        if(isPossible == true)
            answer++;
    }
    
    return answer;
}