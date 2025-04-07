#include <string>
#include <vector>

using namespace std;

enum DIR{
    DOWN = 0,
    RIGHT = 1,
    UP = 2
};

vector<vector<int>> triSnail;
int g_n;

bool CanGo(int x, int y)
{
    if(x < 0 || x >= g_n)
        return false;
    if(y < 0 || y > x)
        return false;
    if(triSnail[x][y] > 0)
        return false;
    return true;
}

vector<int> solution(int n) {
    vector<int> answer;
    int totalNum = n * (n+1) / 2;
    int num = 1;
    int x = 0, y = 0;
    int dir = DOWN;
    int dx[] = {1, 0, -1};  // down, right, up
    int dy[] = {0, 1, -1};  // down, right, up
    
    g_n = n;
    triSnail.resize(n);
    for (int i = 0; i < n; i++)
    {
    	triSnail[i] = vector<int>(i + 1, -1);
    }
    
    while(num <= totalNum)
    {  
        triSnail[x][y] = num;
        
        if (num == totalNum)
		break;
        
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        
        if(CanGo(nextX, nextY))
        {
            x = nextX;
            y = nextY;
            num++;
        }
        else
        {
            dir = (dir + 1) % 3;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < triSnail[i].size(); j++)
        {
            answer.push_back(triSnail[i][j]);
        }
    }
    
    return answer;
}

// 다른 사람 풀이 : 이 방법이면 사각형 만드는 것도 쉬울 듯
// - 사각형이면 p를 줄이는 부분에서 좀 생각해야할 듯
//int arr[1000][1000];
//vector<int> solution(int n) {
//    vector<int> answer;
//    int p = n;
//    int k = 1;
//    int x = -1, y = 0;
//
//    // DOWN, RIGHT, UP을 하는 총 횟수가 n이랑 같음
//    // i는 DOWN, RIGHT, UP을 하는 횟수
//    for (int i = 0; i < n; i++) {
//        // 두번째 for문을 이렇게 할 필요가 없어 보이는데
//        // j는 각 방향마다 채워야할 배열 개수
//        for (int j = p;j >= 1; j--) {
//            // DOWN
//            if(i%3==0) {
//                arr[++x][y] = k;
//            // RIGHT
//            } else if (i % 3 == 1) {
//                arr[x][++y] = k;
//            // UP
//            } else if (i % 3 == 2) {
//                arr[--x][--y] = k;
//            }
//            k++;
//        }
//        p--;
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j <= i;  j++) {
//            answer.emplace_back(arr[i][j]);
//        }
//    }
//
//    return answer;
//}