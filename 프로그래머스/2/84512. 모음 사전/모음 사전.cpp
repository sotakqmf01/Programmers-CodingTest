#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool bFind = false;

void DFS(int depth, string checkWord, const vector<char>& alphabet, string word)
{
    answer++;
    
    if(checkWord == word)
    {
        bFind = true;
        return;
    }

    if(depth < 5)
    {
        for(int i = 0; i < alphabet.size(); i++)
        {
            if(!bFind){
                DFS(depth+1, checkWord + alphabet[i], alphabet, word);
            }
        }
    }
}

int solution(string word) {
    vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};
    string checkWord = "";
    
    DFS(0, checkWord, alphabet, word);

    // 첫 DFS 탐색(문자열에 아무것도 없는 경우)을 빼야함
    return answer-1;
}