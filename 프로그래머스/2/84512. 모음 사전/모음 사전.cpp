#include <string>
#include <vector>

using namespace std;

// 수학적인 풀이도 가능함 생각해보고 해보기

int answer = 0;
bool bFind = false;

// 단어의 길이가 최대 5 => depth 필요
// 현재 단어 => checkWord
// 다음 단어를 위한 알파벳 배열 => vector
// 찾는 단어 => word
void DFS(int depth, string checkWord, const vector<char>& alphabet, string word)
{
    // 알파벳이 빈 문자열이 아닌 경우에만
    if(checkWord != "")
    {
        answer++;
    }
    
    // 찾은 경우에는 더 이상 DFS를 실행하지 않도록 
    if(checkWord == word)
    {
        bFind = true;
        return;
    }

    // 문자의 길이는 최대 5
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

    return answer;
}