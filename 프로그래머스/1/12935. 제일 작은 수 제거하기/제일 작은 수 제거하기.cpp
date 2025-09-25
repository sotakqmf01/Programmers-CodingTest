#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//vector<int> solution(vector<int> arr) {
//    vector<int> answer;
//    int size = arr.size();
//    vector<int>::iterator minit = arr.begin();
//    int min = *minit;
//    
//    if(size == 1){
//        answer.push_back(-1);
//    }
//    else{
//        for(vector<int>::iterator it = arr.begin()+1; it != arr.end(); it++){
//            if( min > *(it) ){
//                min = *(it);
//                minit = it;
//            }
//        }
//        arr.erase(minit);
//        answer = arr;
//    }
//    
//    return answer;
//}

vector<int> solution(vector<int> arr){
    vector<int>::iterator it = min_element(arr.begin(), arr.end());
    arr.erase(it);
    
    if(arr.empty())
        arr.emplace_back(-1);
    
    return arr;
}