#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// vector로도 풀 수 있음
int solution(vector<int> topping){
    int answer = 0;
    // 먹을 수 있는 종류별 토핑의 개수 - Count를 위해 사용
    vector<int> bro(10001, 0);
    vector<int> my(10001, 0);
    // 먹을 수 있는 종류의 수
    int broCount = 0;
    int myCount = 0;
    
    // 일단 동상한태 다 주기
    for(int i = 0; i < topping.size(); i++)
    {
        bro[topping[i]]++;
        if(bro[topping[i]] == 1)
        {
            broCount++;
        }
    }
    
    // 첫 토핑부터 나한태 옮기기
    for(int i = 0; i < topping.size(); i++)
    {
        // 나한태 옮기기
        my[topping[i]]++;
        if(my[topping[i]] == 1)
        {
            myCount++;
        }
        
        // 나한태 옮긴거 동생한태서 빼기
        bro[topping[i]]--;
        if(bro[topping[i]] == 0)
        {
            broCount--;
        }
                
        if(broCount == myCount)
        {
            answer++;
        }
    }

    return answer;
}

//테스트 7 〉	통과 (218.08ms, 37.5MB)
//테스트 8 〉	통과 (216.74ms, 37.5MB)
//테스트 9 〉	통과 (243.36ms, 37.4MB)
//테스트 10 〉	통과 (237.21ms, 37.5MB)
//테스트 11 〉	통과 (7.23ms, 6.31MB)
//테스트 12 〉	통과 (7.23ms, 4.43MB)
//테스트 13 〉	통과 (278.30ms, 37.4MB)

//int solution(vector<int> topping){
//    int answer = 0;
//    map<int, int> bro;
//    map<int, int> my;
//    
//    // 일단 동생한태 모든 토핑 다 주기
//    for(const int& top : topping)
//    {
//        bro[top]++;
//    }
//    
//    // 첫 토핑부터 나한태 옮기기
//    for(const int& top : topping)
//    {
//        // 나한태 옮기기
//        my[top]++;
//        
//        // 나한태 옮긴거 동생한태서 빼기
//        bro[top]--;
//        if(bro[top] == 0)
//        {
//            bro.erase(top);
//        }
//        
//        if(my.size() == bro.size())
//        {
//            answer++;
//        }
//    }
//    
//    return answer;
//}

// 모든 경우의 수
//int CountTopping(vector<int>& topping)
//{
//    sort(topping.begin(), topping.end());
//    
//    vector<int>::iterator it = unique(topping.begin(), topping.end());
//    topping.erase(it, topping.end());
//    
//    return topping.size();
//}
//
//int solution(vector<int> topping) {
//    int answer = 0;
//    
//    for(int i = 1; i <= topping.size()-2; i++)
//    {
//		vector<int> broTopping(topping.begin(), topping.begin() + i);
//		vector<int> myTopping(topping.begin() + i, topping.end());
//
//		int bro = CountTopping(broTopping);
//		int my = CountTopping(myTopping);
//        
//        if(bro == my)
//        {
//            answer++;
//        }
//    }
//    
//    return answer;
//}