#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    char X;

    while(!s.empty())
    {
        X = s[0];
        int Index = 0;
        int CountX = 0;
        int CountNotX = 0;
        
        for(char c : s)
        {
            if(c == X)
            {
                CountX++;
                Index++;
            }
            else
            {
                CountNotX++;
                Index++;
            }
            
            if(CountX == CountNotX)
            {
                s = s.substr(Index);
                answer++;
                break;
            }
        }
        
        // 문자열을 끝까지 비교했을 때 두 횟수가 같아지지 않았을 때
        if(CountX != CountNotX && Index == s.size())
        {
            answer++;
            break;
        }
    }
    
    return answer;
}