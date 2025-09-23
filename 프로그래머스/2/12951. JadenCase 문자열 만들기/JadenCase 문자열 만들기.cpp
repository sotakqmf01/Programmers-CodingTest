#include <string>
#include <vector>

using namespace std;

//string solution(string s) {
//    string answer = "";
//    string Word = "";
//    
//    // 다른 사람 풀이 보기
//    for(char c : s)
//    {
//        if(c == ' ')
//        {
//            if(!Word.empty())
//            {
//                Word[0] = toupper(Word[0]);
//                answer += Word;
//                Word = "";
//            }
//            answer += c;
//        }
//        else
//        {
//            Word += tolower(c);
//        }
//    }
//    
//    if(!Word.empty())
//    {
//        Word[0] = toupper(Word[0]);
//        answer += Word;
//        Word = "";
//    }
//        
//    return answer;
//}


string solution(string s) {
    string answer = "";
    string word = "";
    
    for(char c : s){
        if(c != ' '){
            word += tolower(c);
        }
        else{
            word[0] = toupper(word[0]);
            answer += word;
            word = "";
            answer += c;
        }
    }
    
    word[0] = toupper(word[0]);
    answer += word;
    
    return answer;
}