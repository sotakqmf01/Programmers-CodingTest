#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int standardKey = 0;

//bool compare(const vector<int>& tuple1, const vector<int>& tuple2){
//    if(tuple1[standardKey - 1] == tuple2[standardKey - 1]){
//        return tuple1[0] > tuple2[0];
//    }
//    
//    return tuple1[standardKey -1] < tuple2[standardKey - 1];
//}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int S_i = 0;
    int hash = 0;
    standardKey = col;
    
    //sort(data.begin(), data.end(), compare);
    
    sort(data.begin(), data.end(), [col](const vector<int>& tuple1, const vector<int>& tuple2){
        return (tuple1[col - 1] == tuple2[col - 1]) ? (tuple1[0] > tuple2[0]) : (tuple1[col - 1] < tuple2[col - 1]);
    });
        
    for(int i = row_begin - 1; i < row_end; i++){
        S_i = 0;
        
        for(int j = 0; j < data[i].size(); j++){
            S_i += data[i][j] % (i+1);
        }
        
        hash ^= S_i;
    }
    
    return hash;
}

//bool compare(vector<int> tuple1, vector<int> tuple2){
//    if(tuple1[standardKey - 1] < tuple2[standardKey - 1]){
//        return true;
//    }
//    else if(tuple1[standardKey - 1] > tuple2[standardKey - 1]){
//        return false;
//    }
//    else{
//        if(tuple1[0] > tuple2[0])
//            return true;
//        else
//            return false;
//    }
//}
