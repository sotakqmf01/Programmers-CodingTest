#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GetGCD(int a, int b)
{
    if(b == 0)  return a;
    
    return GetGCD(b, a%b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    int num = arr[0];
    int gcd = 0;
    int lcm = 0;
    
    for(int i = 1; i<arr.size(); i++)
    {
        gcd = GetGCD(num, arr[i]);
        cout << "gcd : " << gcd << endl;
        lcm = num * arr[i] / gcd;
        num = lcm;
        cout << num << endl;
    }
    
    return num;
}