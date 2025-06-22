#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

// 그룹을 한 번만 찾기 위해 중복은 전부 피해야함
// ex) 입출력 예시의 [1, 4, 7, 8]의 경우
//     - 4개의 숫자 중 하나(1)가 DFS를 시작해서 그룹을 찾으면, 나머지들(4, 7, 8)로는 찾을 필요가 없음
int DFS(int startIndex, int depth, const vector<int>& cards, vector<bool>& visited){
    stack<pair<int, int>> st;
    
    st.emplace(startIndex, depth);
    
    while(!st.empty()){
        int prevIndex = st.top().first;
        int prevDepth = st.top().second;
        cout << "prevIndex : " << prevIndex << ", prevDepth : " << prevDepth << endl;
        st.pop();
        
        int currIndex = cards[prevIndex] - 1;
        
        // 그룹을 한 번 찾고나면 여기서 그 그룹을 이루는 나머지들도 걸러짐
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
    
    // 전체 DFS 실행
    // - DFS에서 사이클이 생기면, 그 사이클을 이루는 노드들이 박스가 되고, 그룹이 되는 형태
    //   - 이 그룹에 있는 원소(노드)들은 어떤 걸 선택해도 같은 그룹이 나옴
    // => 그룹만 찾으면 됨
    for(int i = 0; i < cards.size(); i++){
        int boxesOfGroup = DFS(i, 0, cards, visited);
        boxesOfGroups.push_back(boxesOfGroup);
    }
    
    sort(boxesOfGroups.begin(), boxesOfGroups.end(), greater<int>());
    
    for(int boxes : boxesOfGroups){
        cout << "Box : " << boxes << endl;
    }
    
    if(boxesOfGroups.size() == 1){
        return 0;
    }
    
    return boxesOfGroups[0] * boxesOfGroups[1];
}