#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int size = arr.size();
    vector<int>::iterator minit = arr.begin();
    int min = *minit;
    
    if(size == 1){
        answer.push_back(-1);
    }
    else{
        for(vector<int>::iterator it = arr.begin(); it != arr.end()-1; it++){
            if( min > *(it+1) ){
                min = *(it+1);
                minit = it+1;
            }
        }
        arr.erase(minit);
        answer = arr;
    }
    
    return answer;
}