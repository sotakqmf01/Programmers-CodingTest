#include <string>
#include <vector>

using namespace std;

//bool solution(string s) {
//    int len = s.length();
//    
//    if(len != 4 && len != 6)
//        return false;
//    
//    for(int i = 0; i < len; i++){
//        if(s[i] >= 'A')
//            return false;
//        //if(!(s[i] >= '0' && s[i] <= '9'))
//        //    return false;
//    }
//    
//    return true;
//}

bool solution(string s){
    int length = s.length();
    
    if(length != 4 && length != 6)
        return false;
    
   for(const char& c : s){
       if(!isdigit(c))
           return false;
   }
    
    return true;
    
}