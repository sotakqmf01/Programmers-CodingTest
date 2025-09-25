#include <string>
#include <vector>

using namespace std;

//int solution(vector<int> numbers) {
//    int answer = 0;
//    int compare[10] = {1,1,1,1,1,1,1,1,1,1};
//    
//    for(int i = 0; i<numbers.size(); i++){
//        compare[numbers[i]] = 0;
//    }
//    
//    for(int i = 0; i<10; i++){
//        if(compare[i] != 0)
//            answer += i;
//    }
//    
//    return answer;
//}


int solution(vector<int> numbers){
    int answer = 0;
    vector<bool> check(10, false);
    
    for(const int num : numbers){
        check[num] = true;
    }
    
    for(int i = 0; i < check.size(); i++){
        if(check[i] == false)
            answer += i;
    }
    
    return answer;
}