#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//bool IsPrime(int num)
//{
//    for(int i = 2; i <= sqrt(num); i++){
//        if(num % i == 0){
//            // 나머지가 0되는게 있으면 소수가 아님
//            return false;
//        }   
//    }
//    return true;
//}

bool IsPrime(int n)
{
    if(n == 1)
    {
        return false;
    }
    
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    vector<int> combination(nums.size(), 1);
    //fill(combination.end()-3, combination.end(), 1);
    fill(combination.begin(), combination.begin()+3, 0);
    
    do{
        int sumOfNum = 0;
        for(int i = 0; i < nums.size(); i++)
        {   
            // 0으로 하면 순열 순서가 오름차순이 되서 보기 편함
            if(combination[i] == 0)
            {
                sumOfNum += nums[i];
            }
        }
        
        if(IsPrime(sumOfNum))
            answer++;
        
    }while(next_permutation(combination.begin(), combination.end()));
    
    return answer;
}