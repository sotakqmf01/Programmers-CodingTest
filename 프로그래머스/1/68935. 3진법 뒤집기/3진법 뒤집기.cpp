#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str = "";
    long long num;
    
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    
    while(n >= 3){
        str = str + to_string(n % 3);
        n /= 3;
        if(n < 3)
            str = str + to_string(n);
    }
    
    num = stoll(str);
    int exp = 0;
    while(num > 0){
        answer = answer + (num % 10) * pow(3, exp);
        num /= 10;
        exp++;
    }
    
    return answer;
}