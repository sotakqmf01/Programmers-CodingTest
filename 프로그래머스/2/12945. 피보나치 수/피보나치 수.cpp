#include <string>
#include <vector>

using namespace std;

// 나머지 연산 법칙
// - (A + B) % C = (A % C + B % C) % C
// => f(n) % 1234567 = (f(n-1) + f(n-2)) % 1234567
//                   = (f(n-1) % 1234567 + f(n-2) % 1234567) % 1234567
vector<long long> Fibonacci = {0, 1};

int solution(int n) {
    int answer = 0;
    
    for(int i = 0; i <= n - 2; i++)
    {
        Fibonacci.push_back((Fibonacci[i] + Fibonacci[i+1]) % 1234567);
    }
   
    return Fibonacci[n];
}

//int solution(int n){
//    vector<long long> fibonacci(n+1, 0);
//    fibonacci[1] = 1;
//    
//    for(int i = 2; i <= n; i++){
//        fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2]) % 1234567;
//    }
//        
//    return fibonacci[n];
//}