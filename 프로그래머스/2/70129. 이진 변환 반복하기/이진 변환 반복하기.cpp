#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int DeletedZeroCount = 0;
    int TransCount = 0;
    string NewStr = "";
    
    while(s != "1")
    {
        // 0 제거
        NewStr.clear();
        for(char c : s)
        {
            if(c == '1')
            {
                NewStr += c;
            }
            else
            {
                DeletedZeroCount++;
            }
        }

        // 0 제거 후 길이
        int len = NewStr.length();
        
        // 길이 이진 변환
        s.clear();
        while(len > 0)
        {
            s += len % 2 + '0';
            len /= 2;
        }
        reverse(s.begin(), s.end());
        
        TransCount++;
    }
    
    answer.push_back(TransCount);
    answer.push_back(DeletedZeroCount);
    
    return answer;
}