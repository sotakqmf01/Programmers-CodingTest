#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;
    
    int minDist = INT_MAX;
    
    for(const vector<int>& ball : balls){
        left = (int)pow(startX + ball[0], 2) + (int)pow(startY - ball[1], 2);
        right = (int)pow(2*m - startX - ball[0], 2) + (int)pow(startY - ball[1], 2);
        up = (int)pow(startX - ball[0], 2) + (int)pow(2*n - startY - ball[1], 2);
        down = (int)pow(startX - ball[0], 2) + (int)pow(startY + ball[1], 2);
        
        if(startX == ball[0]){
            if(startY > ball[1])
                minDist = min(up, min(left, right));
            else
                minDist = min(down, min(left, right));
        }
        else if(startY == ball[1]){
            if(startX > ball[0])
                minDist = min(right, min(up, down));
            else
                minDist = min(left, min(up, down));
        }
        else{
            minDist = min(min(left, right), min(up, down));
        }
        
        answer.push_back(minDist);
    }
    
    return answer;
}