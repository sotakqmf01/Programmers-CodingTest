#include <string>
#include <vector>
#include <cmath>

using namespace std;

//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//    
//    for(int i = 1; i <= sqrt(yellow); i++)
//    {
//        if(yellow % i == 0)
//        {
//            int j = yellow / i;
//            if(((j + 1) * 2 + (i + 1) * 2) == brown)
//            {
//                answer.push_back(j+2);
//                answer.push_back(i+2);
//            }
//        }
//    }
//    
//    return answer;
//}

// w * h = total
// - w와 h는 total의 약수들임
//  - 3부터 시작하는 이유 : 노란색 격자가 있으려면 2는 불가능
//vector<int> solution(int brown, int yellow){
//    vector<int> answer(2, 0);
//    int total = brown + yellow;
//    
//    for(int i = 3; i*i <= total; i++){
//        if(total % i == 0){
//            if(2*(i + (total / i)) - 4 == brown){
//                answer[0] = total / i;
//                answer[1] = i;
//                break;
//            }
//        }
//    }
//        
//    return answer;
//}

// 다른 사람 풀이
// yellow = (w-2) * (h-2)
// brown = w * h - yellow = 2(w+h - 2)
// => w + h = brown/2 + 2
vector<int> solution(int brown, int yellow){
    vector<int> answer(2, 0);
    
    // 노란색 격자가 있으려면 h=3부터
    int h = 3;
    int w = (brown/2 + 2) - h;
    
    while(w * h != brown + yellow){
        h++;
        w--;
    }
    
    answer[0] = w;
    answer[1] = h;
    
    return answer;
}