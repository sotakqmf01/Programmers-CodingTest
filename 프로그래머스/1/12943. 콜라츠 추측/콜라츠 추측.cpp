#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    if(num == 1)
        return 0;
    
    int answer = 0;
    long long n = num;
    
    while(n != 1){
        if(answer >= 500)
            return -1;
        
        if(n % 2 == 0)
            n = n / 2;
        else
            n = n*3 + 1;
        
        answer++;
    }
    
    return answer;
}


//int solution(int num){
//    int answer = 0;
//    long long temp = num;
//    int count = 0;
//    
//    while(temp != 1){
//        if(temp % 2 == 0)
//            temp /= 2;
//        else
//            temp = temp * 3 + 1;
//        
//        count++;
//        if(count >= 500){
//            return -1;
//        }
//    }
//    
//    answer = count;
//    
//    return answer;
//}