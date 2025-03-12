#include <string>
#include <vector>

using namespace std;

// 이중 for문
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    // 배열의 뒤에서부터 체크
    for(int i = numbers.size() - 2; i >= 0; i--)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            if(numbers[i] < numbers[j])
            {
                answer[i] = numbers[j];
                break;
            }
            // numbers[i] >= numbers[j]인 경우
            else    
            {
                // numbers[j]에 뒷 큰수가 없는 경우
                if(answer[j] == -1)
                {
                    answer[i] = -1;
                    break;
                }
                // numbers[j]에 뒷 큰수(A)가 있는 경우
                // - numbers[i]가 뒷 큰수(A)보다 작은 경우는 numbers[i]의 뒷 큰수도 A가 됨
                // - numbers[i]가 뒷 큰수(A)보다 작지 않은 경우는 뒷 큰수(A)의 뒷 큰수가 있는지 확인하러 가야함
                //   - 두번째 for문이 해결해줌
                else if(numbers[i] < answer[j])
                {
                    answer[i] = answer[j];
                    break;
                }
            }
        }
    }
  
    return answer;
}

// 가장 간단 - 이중 for문 => 시간 초과
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//    bool bFind = false;
//    
//    for(int i = 0; i < numbers.size(); i++)
//    {
//        bFind = false;
//        for(int j = i + 1; j < numbers.size(); j++)
//        {
//            if(numbers[i] < numbers[j])
//            {
//                bFind = true;
//                answer.push_back(numbers[j]);
//                break;
//            }
//        }
//        if(!bFind)
//        {
//            answer.push_back(-1);
//        }
//    }
//    
//    return answer;
//}