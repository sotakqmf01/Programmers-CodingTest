#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % divisor == 0)
            answer.push_back(arr[i]);
    }
    
    for(int i = 1; i < answer.size(); i++){
        for(int j = i; j > 0; j--){
            if(answer[j - 1] > answer[j]){
                int temp = answer[j];
                answer[j] = answer[j-1];
                answer[j-1] = temp;
            }
        }
    }
    
    if(answer.size() == 0)
        answer.push_back(-1);
    
    return answer;
}