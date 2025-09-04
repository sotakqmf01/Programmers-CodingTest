#include <string>
#include <vector>

using namespace std;

int ScoreDiff(const vector<int>& info, const vector<int>& temp){
    // 점수 계산
    int apitch = 0;
    int lion = 0;
    for(int i = 0; i<info.size(); i++){
        if(info[i] > temp[i]){
            apitch += info.size() - 1 - i;
        }
        else if(info[i] < temp[i]){
            lion += info.size() - 1 - i;
        }
        else{
            if(info[i] != 0)
                apitch += info.size() - 1 - i;
        }
    }
    
    return lion - apitch;
}

bool TieBreak(const vector<int>& answer, const vector<int>& temp){
    for(int i = answer.size() - 1; i >= 0; i--){
        if(answer[i] != temp[i])
            return answer[i] < temp[i];
    }
    
    return false;
}

void CompareScore(const vector<int>& info, vector<int>& answer, vector<int>& temp){
    int tempScoreDiff = ScoreDiff(info, temp);
    if(tempScoreDiff <= 0)
        return;
    
    int answerScoreDiff = ScoreDiff(info, answer);
    if(tempScoreDiff > answerScoreDiff || (tempScoreDiff == answerScoreDiff && TieBreak(answer, temp)))
        answer = temp;
}

void dfs(int depth, int n, const vector<int>& info, vector<int>& answer, vector<int>& temp){
    if(n == 0){
        CompareScore(info, answer, temp);
        return;
    }
    
    if(depth == info.size() - 1){
        if (n > 0){
            // ★★백트래킹
            temp[info.size() - 1] += n;
            CompareScore(info, answer, temp);
            temp[info.size() - 1] -= n;
        }
        return;
    }
    
    for(int i = 0; i <= n; i++){
        // ★백트래킹
        temp[depth] = i;
        dfs(depth + 1, n - i, info, answer, temp);
        temp[depth] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer((int)info.size(), 0);
    vector<int> temp((int)info.size(), 0);
    
    dfs(0, n, info, answer, temp);
    
    if(ScoreDiff(info, answer) <= 0)
        return vector<int>{-1};
    
    return answer;
}