#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> Alphabet(26, 1);
    
    for(char c : skip)
    {
        Alphabet[c-'a'] = -1;
    }
    
    for(char c : s)
    {
        int AdditionalIndex = index;
        for(int i = 1; i <= AdditionalIndex; i++)
        {
            // 알파벳 개수인 26(0~25)에 맞게 index 조정
            int RealIndex = (c-'a'+i <= 25) ? c-'a'+i : (c-'a'+i) % 26;
            
            // Skip해야할 문자면 for문을 한 번 더 돌게
            if(Alphabet[RealIndex] == -1)
            {
                AdditionalIndex++;
            }
            
            if(i == AdditionalIndex)
            {
                answer += 'a' + RealIndex;
            }
        }
    }
    
    
    return answer;
}