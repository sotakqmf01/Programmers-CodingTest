#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> nephew = {"aya", "ye", "woo", "ma"};
    
    for(string babble : babbling){
        int NextStringIndex = 0;
        bool isPossible = true;
        int PrevNephewIndex = -1;
        
        // 0. 해당 문자열을 발음할 수 있는지 확인하기 위해 문자열이 끝날 때까지 반복
        while(NextStringIndex < babble.length() && isPossible){
            // 1. 발음할 수 있는 각 발음에 대해
            for(int i = 0; i<nephew.size(); i++){
                // 1. 같은 길이만큼 문자열과 비교
                if(babble.compare(NextStringIndex, nephew[i].length(), nephew[i], 0, nephew[i].length()) == 0){
                    // 2. 연속 발음 못함
                    if(PrevNephewIndex == i) { isPossible = false; }
                    else{
                        NextStringIndex += nephew[i].length();
                        PrevNephewIndex = i;
                        isPossible = true;
                        break;
                    }
                }
                else{
                    isPossible = false;
                }
            }
        }
        if(isPossible == true)
            answer++;
    }
    
    return answer;
}