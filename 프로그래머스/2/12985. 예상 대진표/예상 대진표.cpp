#include <iostream>
#include <cmath>

using namespace std;

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