#include <string>
#include <vector>
#include <stack>

using namespace std;

// 괄호 문자열이 올바른지 확인
//bool CheckCorrect(string s)
//{
//    string CheckS = ""; // stack 사용
//    
//    // 괄호 문자열이 올바른지 확인하려면 가장 안쪽 괄호부터 체크해야 함
//    // ex) [([)]] - X / [([])] - O
//    for(char c : s)
//    {
//        // 여는 괄호는 그냥 추가
//        if(c == '[' || c == '{' || c == '(')
//            CheckS += c;
//        else
//        {
//            // 닫는 괄호는 문자열 마지막 괄호와 짝이 맞는지 비교
//            if(CheckS.empty())
//                return false;
//            else if(CheckS.back() == '[' && c == ']')
//                CheckS.erase(CheckS.length() - 1);
//            else if(CheckS.back() == '{' && c == '}')
//                CheckS.erase(CheckS.length() - 1);
//            else if(CheckS.back() == '(' && c == ')')
//                CheckS.erase(CheckS.length() - 1);
//            else
//                return false;
//        }
//    }
//    
//    if(CheckS.empty())
//        return true;
//    else
//        return false;
//}
//
//int solution(string s) {
//    int answer = 0;
//    
//    // 괄호 문자열 회전
//    for(int i = 0; i < s.length(); i++)
//    {
//        char c = s[0];
//        s.erase(s.begin()); 
//        s += c;
//        // s = s.substr(1) + s[0];
//        
//        if(CheckCorrect(s))
//            answer++;
//    }
//    
//    return answer;
//}

// 현재 문자열만 체크하면 됨
bool checkString(const string& s, int start){
    stack<char> st;
    int length = s.length();
    
    for(int i = 0; i < length; i++){
        char c = s[(i + start) % length];
        if(c == '[' || c == '(' || c == '{')
            st.push(c);
        else{
            if(st.empty())
                return false;
            else if(c == ']' && st.top() == '[')
                st.pop();
            else if(c == '}' && st.top() == '{')
                st.pop();
            else if(c == ')' && st.top() == '(')
                st.pop();
            else
                return false;
        }
    }
    
    if(st.empty())
        return true;
    else
        return false;
}

int solution(string s){
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(checkString(s, i))
            answer++;
    }
    
    return answer;
}