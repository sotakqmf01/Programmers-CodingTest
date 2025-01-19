#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 유클리드 호제법
int getGcd(int a, int b){
    if(b == 0) return a;
    return getGcd(b, a%b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int num = n < m ? n : m;
    
    // 연제법(동시에 나눌 수 있는 수로 계속 나누기)
    int gcd_n = m;
    int gcd_m = n;
    int gcd = 1;
    int flag = 1;
    
    while(flag){
        for(int i = 2 ; i <= num; i++){
            if(gcd_n % i == 0 && gcd_m % i == 0){
                gcd *= i;
                gcd_n /= i;
                gcd_m /= i;
                num /= i;
                break;
            }
            // 공약수가 없는 경우
            if(i == num)
                flag = 0;
        }
        if(gcd_n == 1 || gcd_m == 1)
            flag = 0;
    }
    
    int lcm = gcd * gcd_n * gcd_m;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    //for(int i = num; i > 0; i--){
    //    if(n % i == 0 && m % i == 0){
    //        answer.push_back(i);
    //        answer.push_back(n*m/i);
    //        break;
    //    }
    //}
    
    //int gcd = getGcd(n, m);
    //int lsm = n * m / gcd;
    //answer.push_back(gcd);
    //answer.push_back(lsm);
        
    return answer;
}