#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> topping){
    int answer = 0;
    map<int, int> bro;
    map<int, int> my;
    
    // 일단 동생한태 모든 토핑 다 주기
    for(const int& top : topping)
    {
        bro[top]++;
    }
    
    // 나 한태도 토핑 나누기
    for(const int& top : topping)
    {
        my[top]++;
        bro[top]--;
        
        if(bro[top] == 0)
        {
            bro.erase(top);
        }
        
        if(my.size() == bro.size())
        {
            answer++;
        }
    }
    
    return answer;
}

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