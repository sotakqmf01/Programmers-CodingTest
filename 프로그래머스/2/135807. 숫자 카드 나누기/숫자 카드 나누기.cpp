#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int getGCD(int a, int b){
    if(b == 0)
        return a;
    
    return getGCD(b, a%b);
}

// index 0번 숫자와 n번 숫자의 최대 공약수를 구하는 함수
// => GCD 벡터는 index 0번의 약수들로만 이루어짐
//  - (더 큰 약수로 나눌 수 있으면, 더 작은 약수로도 나눌 수 있음)
//  - => 이 중 최소값(α)이 카드덱을 모두 나눌 수 있는 최대값이 됨
//     ❌ 아님
//     ❌ 계속 0번째와 n째의 공약수를 구함 => 그렇다고 구해진 공약수끼리 배수의 관계에 있지 않을 수 있음
//     ❌ - 0번이 10이라고 했을 때 n1과의 공약수는 2, n2와의 공약수는 5라고 했을 때
// ▶ 반례 : [30, 20, 12], [7, 9, 19]
// => 모든 카드 수의 공약수를 구해야함
// ▶️ 이 공약수(α')의 약수들 중 다른 카드덱을 하나도 나눌 수 없는 수가 a가 됨
int arrayGCD(vector<int>& cardPack){
    int gcdOfArray = cardPack[0];
    
    for(int num : cardPack){
        gcdOfArray = getGCD(num, gcdOfArray);
    }
    
    return gcdOfArray;
}

int checkOtherPack(int GCD, vector<int>& otherPack){
    int maxDivisior = 0;
    
    // GCD의 약수(Divisior)들 중
    for(int i = 2; i <= GCD; i++){
        if(GCD % i == 0){
            bool bCanDivide = false;
            
            // 다른 카드팩의 모든 숫자를 나눌 수 없는 약수 찾기
            for(int num : otherPack){
                if(num % i == 0){
                    bCanDivide = true;
                    break;
                }
            }
            
            if(!bCanDivide)
                maxDivisior = max(maxDivisior, i);
        }
    }
    
    return maxDivisior;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int gcdOfA = arrayGCD(arrayA);
    int gcdOfB = arrayGCD(arrayB);
    
    answer = max(checkOtherPack(gcdOfA, arrayB), checkOtherPack(gcdOfB, arrayA));
    
    return answer;
}

//int solution(vector<int> arrayA, vector<int> arrayB) {
//    int answer = 0;
//    // 일단 하다보니까 이 벡터들이 없어도 될 것 같음
//    //vector<int> AGCD;
//    //vector<int> BGCD;
//    
//    sort(arrayA.begin(), arrayA.end());
//    sort(arrayB.begin(), arrayB.end());
//    
//    int minOfA = arrayGCD(AGCD, arrayA);
//    cout << "minOfA : " << minOfA << endl;
//    int minOfB = arrayGCD(BGCD, arrayB);
//    cout << "minOfB : " << minOfB << endl;
//    
//    answer = max(checkOtherPack(minOfA, arrayB), checkOtherPack(minOfB, arrayA));
//    
//    return answer;
//}