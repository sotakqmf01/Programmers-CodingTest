#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    string Word = "";
    
    for(char c : s)
    {
        if(c == ' ')
        {
            if(!Word.empty())
            {
                Word[0] = toupper(Word[0]);
                answer += Word;
                Word = "";
            }
            answer += c;
        }
        else
        {
            Word += tolower(c);
        }
    }
    
    if(!Word.empty())
    {
        Word[0] = toupper(Word[0]);
        answer += Word;
        Word = "";
    }
        
    return answer;
}