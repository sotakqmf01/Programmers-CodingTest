#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// DP만 사용한 코드
vector<int> Mem;

int solution(int x, int y, int n) {
    Mem.resize(y+1);
    // INT_MAX로 초기화를 하면 
    // for문에서 min()할 때 (Mem[i]+1) 부분에서 오버플로우 발생해서
    // (Mem[i]+1)이 엄청 큰 값이 아니라 0이되버림 => INT_MAX보다 조금 작은 값으로 초기화
    fill(Mem.begin(), Mem.end(), INT_MAX-10);
    
    // 기저 사례
    Mem[x] = 0;

    for(int i = x; i <= y; i++){
        if(i+n <= y)
        {
            Mem[i+n] = min(Mem[i+n], Mem[i] + 1);
        }
        if(i*2 <= y)
        {
            Mem[i*2] = min(Mem[i*2], Mem[i] + 1);
        }
        if(i*3 <= y)
        {
            Mem[i*3] = min(Mem[i*3], Mem[i] + 1);
        }
    }
    
    if(Mem[y] == INT_MAX-10) 
    {
        return -1;
    }
    
    return Mem[y];
}

// DFS의 가지 수를 줄이기 위해
// x를 index로 변환하기 위한 최소 연산 횟수를 담을 DP(메모이제이션) 배열 추가
//vector<int> Mem;
//
//void DFS(int depth, int x, int y, int n)
//{
//    // 더 적은 연산 횟수로 x값을 만들 수 있는 경우가 있다면 넘어감
//    if(Mem[x] <= depth)
//    {
//        return;
//    }
//    
//    // 더 적은 연산 횟수로 x값을 만들 수 있는 경우를 찾았으면 DP 배열 갱신
//    Mem[x] = depth;
//    if(x == y)
//    {
//        return;
//    }
//    
//	if (x + n <= y)
//	{
//		DFS(depth + 1, x + n, y, n);
//	}
//	if (x * 2 <= y)
//	{
//		DFS(depth + 1, x * 2, y, n);
//	}
//	if (x * 3 <= y)
//	{
//		DFS(depth + 1, x * 3, y, n);
//	}
//}
//
//int solution(int x, int y, int n) {
//    Mem.resize(y+1);
//    // 최솟값을 담을 배열이기 때문에 아주 큰 값으로 초기화
//    fill(Mem.begin(), Mem.end(), INT_MAX);
//    
//    DFS(0, x, y ,n);
//    
//    // x에서 y로 가는 경우가 없는 경우
//    if(Mem[y] == INT_MAX)
//    {
//        return -1;
//    }
//
//    return Mem[y];
//}

// 제일 처음 생각난게 DFS => y가 커지고 n이 작아짐에 따라 DFS의 가지가 너무 많아짐 => 시간 초과
//int answer = INT_MAX;
//
//void DFS(int depth, int x, int y, int n)
//{
//    // DFS를 멈춰야 할 때
//    if(x >= y)
//    {
//        if(x == y)
//        {
//            answer = min(answer, depth);
//        }
//        return;
//    }
//    
//    DFS(depth+1, x+n, y, n);
//    DFS(depth+1, x*2, y, n);
//    DFS(depth+1, x*3, y, n);
//}
//
//int solution(int x, int y, int n) {
//    DFS(0, x, y ,n);
//
//    if(answer == INT_MAX)
//    {
//        return -1;
//    }
//    return answer;
//}