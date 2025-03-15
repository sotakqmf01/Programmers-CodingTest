#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// x를 index로 변환하기 위한 최소 연산 횟수를 담을 메모이제이션 배열 추가
vector<int> Mem;

void DFS(int depth, int x, int y, int n)
{
    // 더 적은 연산 횟수로 x값을 만들 수 있는 경우가 있다면 넘어감
    if(Mem[x] <= depth)
    {
        return;
    }
    
    // 더 적은 연산 횟수로 x값을 만들 수 있는 경우를 찾았으면 배열 갱신
    Mem[x] = depth;
    if(x == y)
    {
        return;
    }
    
	if (x + n <= y)
	{
		DFS(depth + 1, x + n, y, n);
	}
	if (x * 2 <= y)
	{
		DFS(depth + 1, x * 2, y, n);
	}
	if (x * 3 <= y)
	{
		DFS(depth + 1, x * 3, y, n);
	}
}

int solution(int x, int y, int n) {
    Mem.resize(y+1);
    // 최솟값을 담을 배열이기 때문에 아주 큰 값으로 초기화
    for(int i = 0; i < Mem.size(); i++)
    {
        Mem[i] = INT_MAX;
    }
    
    DFS(0, x, y ,n);
    
    // x에서 y로 가는 경우가 없는 경우
    if(Mem[y] == INT_MAX)
    {
        return -1;
    }

    return Mem[y];
}

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