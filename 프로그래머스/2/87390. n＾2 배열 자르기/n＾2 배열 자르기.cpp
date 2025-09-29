#include <string>
#include <vector>

using namespace std;

//vector<int> solution(int n, long long left, long long right) {
//    vector<int> answer;
//    
//    // 1. 그림 그려보니까 arr[x][y]의 값이 x와 y 둘 중 큰 값에 +1 한 것(index는 0부터 시작하니까)
//    // 2. 거기에 left와 right를 2차원 좌표로 변환하면 해당 위치의 값을 알 수 있겠다고 생각
//    //    - 각각의 좌표는 (x = left / n), (y = left % n) 로 구할 수 있음
//    // => 그럼 그냥 left ~ right까지 2번 작업을 하고 1번 작업을 하면 1차원 배열 바로 만들 수 있겠다고 생각
//    for(long long i = left; i <= right; i++)
//    {
//        if(i/n > i%n)
//        {
//            answer.push_back(i/n + 1);
//        }
//        else
//        {
//            answer.push_back(i%n + 1);
//        }
//        
//        // STL 활용을 잘하자
//        // answer.push_back(max(i/n, i%n) + 1);
//    }
//    
//    return answer;
//}


vector<int> solution(int n, long long left, long long right){
    vector<int> answer;
    
    for(long long i = left; i <= right; i++){
        int value = (i / n) > (i % n) ? (i / n) + 1 : (i % n) + 1;
        answer.push_back(value);
    }
    
    return answer;
}