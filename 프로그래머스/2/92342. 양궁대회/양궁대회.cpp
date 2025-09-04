#include <string>
#include <vector>

using namespace std;

// 비트 마스킹을 사용한 풀이도 해보기
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
        // ★백트래킹 - 분배형
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

// 다른 사람 풀이
//int N, ans;
//vector<int> answer;
//int a[11];
//int r[11];
//void solve(int cnt, int idx) {
//    if(cnt == N) {
//        int asum = 0;
//        int rsum = 0;
//        for(int i=0; i<=10; i++) {
//            if(a[i]==r[i] && a[i] == 0) continue;
//            if(r[i] > a[i]) rsum += i;
//            else asum += i;
//        }
//        if(ans < rsum-asum) {
//            ans = rsum-asum;
//            answer.clear();
//            for(int i=10; i>=0; i--) {
//                answer.push_back(r[i]);
//            }
//        }
//    }
//    // 백트래킹 - 누적형
//    for(int i=idx; i<=10; i++) {
//        if(a[i] >= r[i]) {
//            r[i]++;
//            solve(cnt+1, i);
//            r[i]--;
//        }
//    }
//}
//
//vector<int> solution(int n, vector<int> info) {
//    N = n;
//    for(int i=10; i>=0; i--) a[10-i] = info[i];
//    solve(0, 0);
//    if(answer.empty()) answer.push_back(-1);
//    return answer;
//}

// 질문하기 - 다른 사람 풀이
//#include <functional>
//
//vector<int> solution(int n, vector<int> info) {
//    vector<vector<int>> answers;
//    int ryan = 0, apeach = 0;
//
//    for (int i = 0; i < info.size(); ++i){
//        if (0 < info[i]){
//            apeach += 10 - i;
//        }
//    }
//
//    vector<int> counts(11, 0);
//    function<void(int, int, int)> dfs = 
//        [&](int idx, int rest, int sum) {
//            if (0 == rest){
//                if (ryan <= sum){
//                    if (ryan < sum){
//                        answers.clear();
//                    }
//                    ryan = sum;
//                    answers.push_back(counts);
//                }
//                return;
//            }
//    
//            int promising = (10 - idx) * (11 - idx) / 2 * 2;
//            if (0 < 10 - idx - rest){
//                promising -= (10 - idx - rest) * (11 - idx - rest) / 2 * 2;
//            }
//            if (sum + promising <= apeach || sum + promising < ryan){
//                return;
//            }
//    
//            if (10 > idx && 0 < rest - info[idx]){
//                counts[idx] = info[idx] + 1;
//                int tmp = 1 < counts[idx] ? sum + (10 - idx) * 2 : sum + (10 - idx);
//                dfs(idx + 1, rest - counts[idx], tmp);
//            }
//    
//            if (10 == idx){
//                counts[idx] = rest;
//            }
//            else{
//                counts[idx] = 0;
//            }
//            dfs(idx + 1, rest - counts[idx], sum);
//            counts[idx] = 0;
//        };
//
//    dfs(0, n, 0);
//
//    if (apeach >= ryan){
//        return { -1 };
//    }
//    else
//    {
//        int answer = 0, max1 = 0, max2 = 0;
//        for (int i = 0; i < answers.size(); ++i){
//            for (int j = answers[i].size() - 1; j >= 0; --j){
//                if (0 < answers[i][j]){
//                    if (max1 < j || (max1 == j && max2 < answers[i][j])){
//                        answer = i;
//                        max1 = j;
//                        max2 = answers[i][j];
//                        break;
//                    }
//                }
//            }
//        }
//        return answers[answer];
//    }
//}