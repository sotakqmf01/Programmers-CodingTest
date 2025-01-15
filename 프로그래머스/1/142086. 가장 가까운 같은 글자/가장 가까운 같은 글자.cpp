#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> alphabet;
    int i = 0;
    
    for(char c : s){
        if(alphabet.find(c) == alphabet.end())
            answer.push_back(-1);
        else
            answer.push_back(i - alphabet[c]);
        alphabet[c] = i;
        i++;
    }    
    
    //vector<int> alphabet(26, -1);
    //int i = 0;
    //
    //for(char c : s)
    //{
    //    if(alphabet[c-'a'] == -1)
    //    {
    //        // 처음 나오면
    //        answer.push_back(-1);
    //    }
    //    else
    //    {
    //        // 이전에 나온적이 있으면
    //        answer.push_back(i - alphabet[c-'a']);
    //    }
    //    alphabet[c-'a'] = i;
    //    i++;
    //}
    
    return answer;
}