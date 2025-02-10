#include <string>
#include <vector>

using namespace std;

vector<long long> Fibonacci = {0, 1};

int solution(int n) {
    int answer = 0;
    
    for(int i = 0; i <= n - 2; i++)
    {
        Fibonacci.push_back((Fibonacci[i] + Fibonacci[i+1]) % 1234567);
    }
   
    return Fibonacci[n];
}