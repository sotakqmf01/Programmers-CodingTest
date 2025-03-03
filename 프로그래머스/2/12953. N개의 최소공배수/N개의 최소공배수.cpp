#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetGCD(int a, int b)
{
    if(b == 0)  return a;
    
    return GetGCD(b, a%b);
}

int solution(vector<int> arr) {    
    sort(arr.begin(), arr.end(), greater<int>());
    
    int num = arr[0];
    int gcd = 0;
    int lcm = 0;

    // lcm(a,b) = a * b / gcd(a,b);
    // lcm(a,b,c) = lcm(lcm(a,b),c) = lcm(a,b) * c / gcd(lcm(a,b),c)
    for(int i = 1; i<arr.size(); i++)
    {
        gcd = GetGCD(num, arr[i]);
        lcm = num * arr[i] / gcd;
        num = lcm;
    }
    
    return num;
}