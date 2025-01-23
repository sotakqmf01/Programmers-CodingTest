#include <string>
#include <vector>
#include <cmath>

using namespace std;

int divisor(int num)
{
    int count = 0;
    
    for(int i = 1; i < sqrt(num); i++)
    {
        if(num % i == 0)
        {
            count += 2;
        }
    }
    
    if(floor(sqrt(num)) == sqrt(num))
    {
        count++;
    }
    
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++)
    {
        int divisorCount = divisor(i);

        if(divisorCount <= limit)
        {
            answer += divisorCount;
        }
        else
        {
            answer += power;
        }
    }
    
    return answer;
}