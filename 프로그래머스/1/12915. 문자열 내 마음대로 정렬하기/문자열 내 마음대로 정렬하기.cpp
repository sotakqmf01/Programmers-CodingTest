#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    int size = strings.size();
    
    // 정렬
    //for(int i = 0; i < size - 1; i++){
    //    for(int j = 0; j < size - 1 - i; j++){
    //        string str1 = strings[j].substr(n, strings[j].length()-1);
    //        string str2 = strings[j+1].substr(n, strings[j+1].length()-1);
    //        if(str1 > str2){
    //            string temp = strings[j];
    //            strings[j] = strings[j+1];
    //            strings[j+1] = temp;
    //        }
    //    }
    //}
    
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(strings[j][n] > strings[j+1][n]){
                string temp = strings[j];
                strings[j] = strings[j+1];
                strings[j+1] = temp;
            }
            if(strings[j][n] == strings[j+1][n]){
                if(strings[j] > strings[j+1]){
                    string temp = strings[j];
                    strings[j] = strings[j+1];
                    strings[j+1] = temp;
                }
            }
        }
    }
    
    return strings;
}