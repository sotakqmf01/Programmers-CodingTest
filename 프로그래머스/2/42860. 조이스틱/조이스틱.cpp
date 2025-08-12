#include <string>
#include <vector>

using namespace std;

// 커서를 한쪽으로 쭉 가는게 이득이 아닐 수 있음 - [JCAAAAZ], [JAAAACD]
// 조작 횟수에 큰 영향을 끼치는건 커서 이동임
// - 알파벳 완성은 어떤 경우에도 같음
// - 커서를 이동하는 걸 최소로 해야함
//   - 1. name의 문자가 'A'가 아닌 경우
//     - 1.1. 그리고 차이를 저장 - 위로 가는게 빠른지, 아래로 가는게 빠른지 체크
//   - 2. 버전1 : index 0을 시작으로 왼쪽/오른쪽 모두 가보면서(BFS 느낌으로) 서로 다른 문자를 전부 찾으면 stop
//     - 2.1. 일단 오른쪽으로 가다가 A만났을 때부터 분기하는게 나을려나? 
//       - 이건 name이 20일 때 통과 못 할 것 같음
//         - 중간 가지치기를 잘하면 잘 되나봄
//   - 2. 버전2 : 잠깐만, 아니면 그냥 A가 아닌 곳의 index를 저장해서 뭘 하는 방법도 있을 거 같은데
//     - 2.1. 이 방식은 성능은 좋아도 좀 복잡할 듯
//     - 2.2. 굳이 저장안하고, 오른쪽으로 순서대로 가면서 해도 될 듯

// ★★★★ 가로 이동 횟수 ★★★★
// 가로 이동은 0번 인덱스에서 시작하니까 왼쪽으로 갈 수도 있고, 오른쪽으로 갈 수도 있음
// - 근데 연속된 'A'가 있는 경우 : ex) [BBAAAAB]
//   - 1. 뚫고 간다 : 어느 방향으로든 쭉 갔을 때 이동 횟수는 (length-1)회가 됨 
//   - 2. U턴한다.
//     - a. 먼저 왼쪽으로 쭉 이동하는 경우 : 0 -> nextIndex -> 0 -> i
//       - 0에서 nextIndex까지 이동 횟수 = length - nextIndex
//       - nextIndex에서 0까지 이동 횟수 = length - nextIndex
//       - 0에서 i까지 이동 횟수 = i
//       - 총 : 2*(length - nextIndex) + i
//     - b. 먼저 오른쪽으로 쭉 이동하는 경우 : 0 -> i -> 0 -> nextIndex
//       - 0에서 i까지 이동 횟수 = i
//       - i에서 0까지 이동 횟수 = i
//       - 0에서 nextIndex까지 이동 횟수 = length - nextIndex
//       - 총 : 2*i + (length - nextIndex)
//     - c. a, b를 비교해서 더 작은 값 선택
//       - 공통된 부분 i + (length - nextIndex)
//       - 다른 부분에서 최솟값 min(i, (length - nextIndex))
int solution(string name) {
    int answer = 0;
    int length = name.length();
    int minHorizon = length - 1;     // 오른쪽으로만 쭉 간 경우
        
    for(int i = 0; i < length; i++){         
        // 조이스틱 위/아래 조작
        if(name[i] - 'A' <= 13)
            answer += name[i] - 'A';
        else
            answer += 26 - (name[i] - 'A');
        // answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        // 조이스틱 좌/우 조작
        int nextIndex = i + 1;
        while(nextIndex < length && name[nextIndex] == 'A')
            nextIndex++;
        
        // [BBAABAAB]에서 i = 1인 경우의 예시
        //   - 1. 뚫고 간다 : 어느 방향으로든 쭉 갔을 때 이동 횟수는 (length=8-1) = 7회
        //   - 2. U턴한다. ex) [BBAAAAB], [BBAAAABBBB], [BBAABAAAABBB], [BBAAAABAABBB]
        //     - a. 먼저 왼쪽으로 쭉 이동하는 경우
        //       - 마지막 'A' 다음에 있는 문자까지(j=4) 가는 이동 횟수 = length - j = 4회
        //       - 다시 오른쪽으로 와야하니까(U턴) = length - j = 4회
        //       - 첫 'A' 전에 있는 문자까지(i=1) = i = 1회
        //       - [총 : 2*(length - j) + i] = 9회
        //     - b. 먼저 오른쪽으로 쭉 이동하는 경우
        //       - 첫 'A' 전에 있는 문자까지(i=1) = i = 1회
        //       - 다시 왼쪽으로 와야하니까(U턴) = i = 1회
        //       - 마지막 'A' 다음에 있는 문자까지(j=4) = length - j = 4회
        //       - 총 : 2*i + (length - j) = 6회
        //   => 총 2번의 비교가 필요 2번 과정에서 비교, 여기서 나온 최솟값과 length-1과 비교
        int horizonCost = i + (length - nextIndex) + min(i, (length - nextIndex));
        minHorizon = min(minHorizon, horizonCost);
    }
    
    answer += minHorizon;    
    
    return answer;
}