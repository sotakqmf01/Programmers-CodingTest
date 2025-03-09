#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

bool IsPrime(long long n)
{
    if(n == 1)
    {
        return false;
    }
    
    for(long long i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// n을 k진수로 변환한 수를 istringstream을 사용해 조건에 맞는 수를 찾기
int solution(int n, int k) {
    int answer = 0;
    string K_Conversion = "";
    
    // 진법 변환
    while(n > 0)
    {
        K_Conversion += to_string(n%k);
        n = n / k;
    }
    reverse(K_Conversion.begin(), K_Conversion.end());
    
    // 조건에 맞는 수를 찾고 소수인지 검증
    istringstream ISS(K_Conversion);
    string Token;
    while(getline(ISS, Token, '0')){
        // ISS가 "00"이면 Token이 ""가 되는데, 이 경우의 예외처리를 해야함
        if(Token != "")
        {
            long long TokenToNum = stoll(Token);
            if(IsPrime(TokenToNum)){
                answer++;
            }
        }
    }
    
    return answer;
}

// n을 k진수로 변환한 수를 for문을 사용해 조건에 맞는 수 찾기
//int solution(int n, int k) {
//    int answer = 0;
//    string K_Conversion = "";
//    
//    // 진법 변환
//    while(n > 0)
//    {
//        K_Conversion += to_string(n%k);
//        n = n / k;
//    }
//    reverse(K_Conversion.begin(), K_Conversion.end());
//    
//    // 조건에 맞는 소수 찾기
//    // 각 자리수 마다 0인지 아닌지 체크
//    string FindNumStr = "";
//    for(int i = 0; i < K_Conversion.length(); i++)
//    {
//        // 0이면 FindNum 초기화
//        if(K_Conversion[i] == '0')
//        {
//            // FindNum에 값이 있으면 소수인지 확인
//            if(FindNumStr != "")
//            {
//                long long FindNum = stoll(FindNumStr);
//                if(IsPrime(FindNum))
//                {
//                    answer++;
//                }
//            }
//            FindNumStr = "";
//        }
//        // 0이 아니면 FindNum에 추가
//        else
//        {
//            FindNumStr += K_Conversion[i];
//        }
//    }
//    
//    // 마지막 [0P] or [P] 형태 확인
//    if(FindNumStr != "")
//    {
//        long long FindNum = stoll(FindNumStr);
//        if(IsPrime(FindNum))
//        {
//            answer++;
//        }
//    }
//    
//    return answer;
//}