#include <iostream>
#include <cmath>

using namespace std;

// 비트 연산자 사용해야하면 어떻게 할지 생각해보기
int solution(int n, int a, int b)
{
    int Round = 1;

    while(Round <= n)
    {
        if((a+1)/2 == (b+1)/2)
        {
            break;
        }
        else
        {
            a = (a+1)/2;
            b = (b+1)/2;
        }

        Round++;
    }

    return Round;
}