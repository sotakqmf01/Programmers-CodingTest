#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> solution(long long n){
    vector<int> answer;
    
    while(n > 0){
        answer.emplace_back(n % 10);
        n /= 10;
    }
    
    return answer;
}

// 문자열을 사용한 풀이
//vector<int> solution(long long n){
//    vector<int> answer;
//    string nStr = to_string(n);
//
//    for(int i = nStr.length() - 1; i >= 0; i--){
//        answer.emplace_back(nStr[i] - '0');
//        //answer.emplace_back(stoi(nStr.substr(i, 1)));
//        //answer.emplace_back(atoi(nStr.substr(i, 1).c_str()));
//    }
//    
//    return answer;
//}