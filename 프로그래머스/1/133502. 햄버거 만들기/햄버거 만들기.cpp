#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    // size()의 반환값은 size_type(=size_t의 typedef)으로 unsigned int값임
    // size()가 4보다 작을 경우 ingredient.size() - 4가 음수가 아니라 엄청 큰 정수 값이 됨
    // => int로 형변환을 해서 원하는 동작을 하도록 해야함
    for(int i = 0; i <= (int)ingredient.size() - 4; )
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
    
    return answer;
}