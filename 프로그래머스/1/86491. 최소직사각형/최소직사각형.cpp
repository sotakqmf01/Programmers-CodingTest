#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int size = sizes.size();
    
    int w = 0;
    int h = 0;
    
    //for(int i = 0; i < size; i++){
    //    if(sizes[i][0] < sizes[i][1])
    //        swap(sizes[i][0], sizes[i][1]);
    //    
    //    if(w < sizes[i][0])
    //        w = sizes[i][0];
    //    if(h < sizes[i][1])
    //        h = sizes[i][1];
    //}
    
    for(int i = 0; i < size; i++){
        w = max(w, max(sizes[i][0], sizes[i][1]));
        h = max(h, min(sizes[i][0], sizes[i][1]));
    }
    
    answer = w * h;
    
    return answer;
}