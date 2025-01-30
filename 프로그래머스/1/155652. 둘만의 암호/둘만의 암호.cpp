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
            int RealIndex = (c-'a'+i <= 25) ? c-'a'+i : (c-'a'+i) % 26;
            //while(RealIndex > 25)
            //{
            //    RealIndex = RealIndex - 26;
            //}
            
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