#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int t_len = t.length();
    int p_len = p.length();
    
    string sub;
    for(int i = 0; i <= t_len - p_len; i++){
        sub = t.substr(i, p_len);
        if(stoll(sub) <= stoll(p))
            answer++;
    }
    
    return answer;
}