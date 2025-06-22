#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// DFS에서 사이클이 생기면, 그 사이클을 이루는 노드들이 박스가 되고, 그룹이 되는 형태
//   - 이 그룹에 있는 원소(노드)들은 어떤 걸 선택해도 같은 그룹이 나옴
// => 사이클만 찾으면 됨
int DFS(int startIndex, int depth, const vector<int>& cards, vector<bool>& visited){
    stack<pair<int, int>> st;
    
    st.emplace(startIndex, depth);
    
    while(!st.empty()){
        int prevIndex = st.top().first;
        int prevDepth = st.top().second;
        st.pop();
        
        int currIndex = cards[prevIndex] - 1;
        
        // 사이클을 찾음
        // + 그룹을 한 번 찾고나면 여기서 그 그룹을 이루는 나머지들도 걸러짐(이건 solution에서 미리 막았음)
        if(visited[currIndex]){
            return prevDepth;
        }
        
        st.emplace(currIndex, prevDepth + 1);
        visited[currIndex] = true;
    }
    
    // 스택이 비어버리면 사이클이 없음, 뭔가 원인 모를 에러 상황
    return -1;
}

int solution(vector<int> cards) {
    vector<int> boxesOfGroups;
    vector<bool> visited(cards.size(), false);
    
    // 전체 카드 DFS 실행
    // - 그룹을 한 번만 찾기 위해 중복은 전부 피해야함
    // ex) 입출력 예시의 [1, 4, 7, 8]의 경우
    //     - 4개의 숫자 중 하나(1)가 DFS를 시작해서 그룹을 찾으면, 나머지들(4, 7, 8)로는 찾을 필요가 없음
    for(int i = 0; i < cards.size(); i++){
        if(!visited[i]){
            int boxesOfGroup = DFS(i, 0, cards, visited);
            boxesOfGroups.push_back(boxesOfGroup);
        }
    }
    
    sort(boxesOfGroups.begin(), boxesOfGroups.end(), greater<int>());
    
    if(boxesOfGroups.size() == 1){
        return 0;
    }
    
    return boxesOfGroups[0] * boxesOfGroups[1];
}

// 뭔가 어렴풋이 굳이 DFS의 형태를 가지지 않고도 풀 수 있을 거라 생각은 계속 들었지만
// 역시나 누군가 while()문으로 꼬리 물기 식으로 푼 게 있음

// 질문하기 -> https://jinho082008.tistory.com/57
// 카드 묶음을 시작하고 오픈된 카드의 수를 반환하는 함수
//int gameStart(vector<int>& cards) {
//    int startIndex = -1; // 시작 카드 인덱스 초기화
//    int openCount = 0; // 오픈된 카드 수 초기화
//
//    // 첫 번째 오픈 가능한 카드 찾기
//    for(int i = 0; i < cards.size(); i++) {
//        if(cards[i] != 0) { // 카드가 오픈되지 않은 경우
//            startIndex = i; // 시작 인덱스 설정
//            break;			//게임 시작
//        }
//    }
//
//    // 오픈할 카드가 없는 경우
//    if(startIndex == -1)
//        return 0; // 0 반환
//
//    // 카드 묶음을 오픈하는 과정
//    while(cards[startIndex] != 0) { // 현재 카드가 오픈되지 않은 경우
//        int nextIndex = cards[startIndex] - 1; // 다음 카드 인덱스 계산
//        cards[startIndex] = 0; // 현재 카드 오픈 처리
//        startIndex = nextIndex; // 다음 카드로 이동
//        openCount++; // 오픈된 카드 수 증가
//    }
//
//    return openCount; // 오픈된 카드 수 반환
//}
//
//// 전체 카드 배열을 처리하는 함수
//int solution(vector<int> cards) {
//    int answer = 0; // 결과 초기화
//    vector<int> result; // 카드 묶음 크기를 저장할 벡터
//
//    // 카드 묶음을 찾는 과정
//    while(true) {
//        int temp = gameStart(cards); // 카드 묶음의 크기 찾기
//        result.push_back(temp); // 결과에 추가. 0이어도 점수 계산에 필요하기에 push후 종료
//        if(temp == 0) // 더 이상 오픈할 카드가 없으면 종료
//            break;
//    }
//
//    // 묶음 크기를 내림차순으로 정렬
//    sort(result.rbegin(), result.rend());
//
//    // 가장 큰 두 묶음의 곱 반환
//    return result[0] * result[1]; // 두 번째로 큰 묶음이 존재한다고 가정
//}