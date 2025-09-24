#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int sum = 0;
    int n = x;
    
    while(n > 0){
        sum = sum + (n % 10);
        n = n / 10;
    }
    
    if((x % sum) != 0)
        answer = false;
 
    return answer;
}

//bool solution(int x){
//    bool answer = false;
//    int temp = x;
//    int sum = 0;
//    
//    // 각 자리 수의 합
//    while(temp > 0){
//        sum += temp % 10;
//        temp /= 10;
//    }
//    
//    if(x % sum == 0)
//        answer = true;
//    
//    return answer;
//}