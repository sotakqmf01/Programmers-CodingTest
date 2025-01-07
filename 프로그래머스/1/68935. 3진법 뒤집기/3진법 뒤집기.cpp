#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str = "";
    long long num;
     
    while(n > 0){
        str = str + to_string(n % 3);
        n /= 3;
    }
    
    for(char c : str) 
        answer = answer * 3 + (c - '0');
    
    //num = stoll(str);
    
    //int exp = 0;
    //while(num > 0){
    //    answer = answer + (num % 10) * pow(3, exp);
    //    num /= 10;
    //    exp++;
    //}
    
    return answer;
}