#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    vector<int> com(numbers.size());
    fill(com.begin(), com.end()-2, 0);
    fill(com.end()-2, com.end(), 1);
    
    do{
        int sum = 0;
        for(int i = 0; i < com.size(); i++){
            if(com[i] == 1){
                sum += numbers[i];
            }
        }
        s.insert(sum);
    }while(next_permutation(com.begin(), com.end()));
    
    for(int num : s){
        answer.push_back(num);
    }
    sort(answer.begin(), answer.end());
 
    return answer;
}