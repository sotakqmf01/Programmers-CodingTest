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
    
    //if(num % (int)sqrt(num == 0)) - 이거는 제대로 작동 안함(2나 3일때 생각해보기)
    // 실수형은 부동 소수점 오차가 있을 수 있어 비교를 자제해야겠다는 생각이 갑자기 듦
    //if((double)(num / (int)sqrt(num)) == sqrt(num))
    //if(floor(sqrt(num)) == sqrt(num))
    if((int)sqrt(num) * (int)sqrt(num) == num)
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