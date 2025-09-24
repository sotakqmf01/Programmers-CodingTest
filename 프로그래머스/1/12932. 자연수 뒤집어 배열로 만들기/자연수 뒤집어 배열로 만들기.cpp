#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;

//vector<int> solution(long long n){
//    vector<int> answer;
//    
//    while(n > 0){
//        answer.emplace_back(n % 10);
//        n /= 10;
//    }
//    
//    return answer;
//}

// 다른 사람 풀이
vector<int> solution(long long n){
    vector<int> answer;
    string nStr = to_string(n);

    for(int i = nStr.length() - 1; i >= 0; i--){
        answer.emplace_back(nStr[i] - '0');
        // answer.
    }
    
    return answer;
}