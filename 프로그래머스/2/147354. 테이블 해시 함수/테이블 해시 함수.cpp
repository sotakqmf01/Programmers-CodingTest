#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int standardKey = 0;
//
bool compare(vector<int> tuple1, vector<int> tuple2){
    if(tuple1[standardKey - 1] == tuple2[standardKey - 1]){
        return tuple1[0] > tuple2[0];
    }
    
    return tuple1[standardKey -1] < tuple2[standardKey - 1];
}
//
//int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
//    int S_i = 0;
//    int hash = 0;
//    standardKey = col;
//    
//    sort(data.begin(), data.end(), compare);
//        
//    for(int i = row_begin - 1; i < row_end; i++){
//        S_i = 0;
//        
//        for(int j = 0; j < data[i].size(); j++){
//            S_i += data[i][j] % (i+1);
//        }
//        
//        hash ^= S_i;
//    }
//    
//    return hash;
//}


//bool compare(vector<int> tuple1, vector<int> tuple2){
//    if(tuple1[standardKey - 1] < tuple2[standardKey - 1]){
//        return true;
//    }
//    else if(tuple1[standardKey - 1] > tuple2[standardKey - 1]){
//        return false;
//    }
//    else{
//        if(tuple1[0] > tuple1[0])
//            return true;
//        else
//            return false;
//    }
//}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int S_i = 0;
    int hash = 0;
    standardKey = col;
    
    sort(data.begin(), data.end(), compare);
    
    for(int i = row_begin - 1; i < row_end; i++){
        S_i = 0;
        
        for(int j = 0; j < data[i].size(); j++){
            S_i += data[i][j] % (i+1);
        }
        
        if(i == row_begin - 1)
            hash = S_i;
        else
            hash = hash ^ S_i;
    }
    
    return hash;
}