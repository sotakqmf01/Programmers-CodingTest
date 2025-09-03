#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    // 폭격 미사일을 개구간(s,e)에서 최대한 오른쪽에서 요격해야 요격 미사일을 최소한으로 사용할 수 있음
    // - 미사일의 끝(e)이 값이 작을수록 먼저 요격해야함
    //   - 미사일이 길면 앞에서 이미 요격이 되었을수도 있음
    sort(targets.begin(), targets.end(), 
         [](const vector<int>& a, const vector<int>& b){
             return a[1] < b[1];
         });
    
    int interceptor = 0;
    for(const vector<int>& target : targets){
        // 요격 미사일은 최대한 오른쪽에서 발사
        // - 폭격 미사일의 시작(s)이 요격 미사일 좌표보다 작으면, 요격되었으니 넘어감
        // - 정수를 그대로 사용하는 이유는 가장 오른쪽이라는 기준을 잡기 위함임
        //   - 입출력 예시) target 정렬 => {[1,4] [4,5] [3,7] [4,8] .... }
        //     - 2번째 타겟 : 현재 요격 미사일의 좌표는 4, 하지만 if문에서 이 요격 미사일에 의해 2번째 타겟은 요격 처리 X
        // => interceptor가 의미하는 건 해당 정수 좌표에 가까운 실수 좌표(ex 3.9)
        // => 요격 처리는 부등호의 "="을 붙이냐 마냐로 조절 가능
        if(target[0] >= interceptor){
            interceptor = target[1];
            answer++;
        }
    }
    
    return answer;
}