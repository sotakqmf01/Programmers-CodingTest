#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> Alphabet(26, -1);
    
    for(const string& key : keymap)
    {
        for(int i = 0; i<key.length(); i++)
        {
            if(Alphabet[key[i]-'A'] == -1)
            {
                Alphabet[key[i]-'A'] = i+1;
            }
            else if(Alphabet[key[i]-'A'] > i)
            {
                Alphabet[key[i]-'A'] = i+1;
            }
        }
    }
    
    for(const string& target : targets)
    {
        int ClickCount = 0;
        
        for(char c : target)
        {
            if(Alphabet[c-'A'] == -1)
            {
                ClickCount = -1;
                break;
            }
            else
            {
                ClickCount += Alphabet[c-'A'];
            }
        }
        
        answer.push_back(ClickCount);
    }
    
    
    return answer;
}