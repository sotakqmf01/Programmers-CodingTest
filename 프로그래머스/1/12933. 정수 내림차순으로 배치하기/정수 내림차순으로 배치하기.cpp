#include <string>
#include <vector>

using namespace std;

//long long solution(long long n) {
//    long long answer = 0;
//
//    vector<int> v(1, n%10);
//    
//    for(int i=0; n/=10; i++){
//        v.push_back(n%10);
//    }
//    
//    for(int i = 1; i < v.size(); i ++){
//        for(int j = i; j > 0; j--){
//            if(v[j-1] < v[j]){
//                int temp = v[j];
//                v[j] = v[j-1];
//                v[j-1] = temp;
//            } 
//        }
//    }
//    
//    for(int i = 0; i < v.size(); i++){
//        answer = answer * 10 + v[i];
//    }
//    
//    return answer;
//}

#include <algorithm>

long long solution(long long n){
    long long answer = 0;
    
    string s = to_string(n);
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    
    answer = stoll(s);
    
    return answer;
}