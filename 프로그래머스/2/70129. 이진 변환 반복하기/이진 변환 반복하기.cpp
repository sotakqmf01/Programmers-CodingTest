#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//vector<int> solution(string s) {
//    vector<int> answer;
//    int DeletedZeroCount = 0;
//    int TransCount = 0;
//    string NewStr = "";
//    
//    while(s != "1")
//    {
//        // 0 제거
//        NewStr.clear();
//        for(char c : s)
//        {
//            if(c == '1')
//            {
//                NewStr += c;
//            }
//            else
//            {
//                DeletedZeroCount++;
//            }
//        }
//
//        // 0 제거 후 길이
//        int len = NewStr.length();
//        
//        // 길이 이진 변환
//        s.clear();
//        while(len > 0)
//        {
//            s += len % 2 + '0';
//            len /= 2;
//        }
//        // 이진 변환한게 어떻게 나오든 상관 없음
//        // 어짜피 0을 제거할 것이기 때문
//        //reverse(s.begin(), s.end());
//        
//        TransCount++;
//    }
//    
//    answer.push_back(TransCount);
//    answer.push_back(DeletedZeroCount);
//    
//    return answer;
//}

vector<int> solution(string x){
    vector<int> answer(2, 0);
    int conversion = 0;
    int zero = 0;
    
    while(x != "1"){
        int currentZero = count(x.begin(), x.end(), '0');
        zero += currentZero;
        
        int length = x.length() - currentZero;
        x.clear();
        while(length > 0){
            x += to_string(length % 2);
            length /= 2;
        }
        
        conversion++;
    }
    
    answer[0] = conversion;
    answer[1] = zero;
    
    return answer;
}