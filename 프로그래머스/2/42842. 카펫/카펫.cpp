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

vector<int> solution(int brown, int yellow){
    vector<int> answer(2, 0);
    int total = brown + yellow;
    
    for(int i = 3; i*i <= total; i++){
        if(total % i == 0){
            if(2*(i + (total / i)) - 4 == brown){
                answer[0] = total / i;
                answer[1] = i;
                break;
            }
        }
    }
        
    return answer;
}