#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 모든 경우의 수 - 비트 연산
int solution(vector<int> numbers, int target) {
    int answer = 0;
    // n개의 정수가 있을 때, 이 정수의 부호가 + 또는 -인 경우의 수 = 2^n
    // => 각 경우가 비트로 표현되고 [각 비트는 해당 위치의 정수의 부호]를 나타냄
    // ex) n = 3, (000, 001, 010, 011, 100, ..., 111)
    int size = 1 << numbers.size();
    
    // 각 경우에 대해
    for(int i = 0 ; i < size ; i++)
    {
        int sum = 0;
         
        // 비트가 0인 경우는 +, 1인 경우는 -
        // ex) i = 3일 때
        //  - j = 0이면 011 & 001 = 001 = 1 => [-]
        //  - j = 1이면 011 & 010 = 010 = 2 => [-]
        //  - j = 2이면 011 & 100 = 0 => [+]
        for(int j = 0 ; j < numbers.size() ; j++)
        {  
            if(i & (1 << j))
            {
                sum -= numbers[j];
            }
            else 
            {
                sum += numbers[j];
            }
        }
        
        if(sum == target) 
        {
            answer++;
        }
    }
    return answer;
}

// 모든 경우의 수 - permutation
//int solution(vector<int> numbers, int target) {
//    int answer = 0;
//    int sum = 0;
//    vector<int> combi(numbers.size(), 1);
//    
//    // n개의 정수 중 0개를 뺄 경우 ~ n개를 뺄 경우
//    for(int i = 0; i <= numbers.size(); i++)
//    {
//        fill_n(combi.begin(), i, 0);
//        
//        // i개를 뺄 경우의 조합
//        do
//        {
//            sum = 0;
//            
//            // 각 조합에 대한 합
//            for(int j = 0; j < numbers.size(); j++)
//            {
//                if(combi[j] == 0)
//                {
//                    sum -= numbers[j];
//                }
//                else
//                {
//                    sum += numbers[j];
//                }
//            }
//            
//            // 합을 target과 비교
//            if(sum == target)
//            {
//                answer++;
//            }
//        }while(next_permutation(combi.begin(), combi.end()));
//    }
//    
//    return answer;
//}