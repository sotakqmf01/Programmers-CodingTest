#include <string>
#include <vector>

using namespace std;

//vector<long long> Fibonacci = {0, 1};
//
//int solution(int n) {
//    int answer = 0;
//    
//    for(int i = 0; i <= n - 2; i++)
//    {
//        Fibonacci.push_back((Fibonacci[i] + Fibonacci[i+1]) % 1234567);
//    }
//   
//    return Fibonacci[n];
//}

int solution(int n){
    vector<long long> fibonacci(n+1, 0);
    fibonacci[1] = 1;
    
    for(int i = 2; i <= n; i++){
        fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2]) % 1234567;
    }
        
    return fibonacci[n];
}