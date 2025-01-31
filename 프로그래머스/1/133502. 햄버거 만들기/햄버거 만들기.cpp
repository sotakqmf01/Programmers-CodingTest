#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    for(int i = 0; i <= ingredient.size() - 4; )
    {
        if(ingredient.size() >= 4)
        {
            if(ingredient[i] == 1 && ingredient[i+1] == 2 && ingredient[i+2] == 3 && ingredient[i+3] == 1)
            {
                ++answer;
                vector<int>::iterator it = ingredient.begin() + i;
                ingredient.erase(it, it+4);
                i = (i - 3 >= 0) ? i - 3 : 0;
            }
            else
            {
                ++i;
            }
        }
        else
        {
            break;
        }
    }
    
    return answer;
}