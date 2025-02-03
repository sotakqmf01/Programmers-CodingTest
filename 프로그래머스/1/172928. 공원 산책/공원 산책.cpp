#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 다른 사람 풀이 봐야함
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int ParkHeight = park.size();
    int ParkWidth = park[0].size();
    int StartX = 0;
    int StartY = 0;
    
    for(int i = 0; i < ParkHeight; i++){
        for(int j = 0; j < ParkWidth; j++){
            if(park[i][j] == 'S'){
                StartX = j;
                StartY = i;
            }
        }
    }
    
    for(const string& route : routes)
    {
        char direction = route[0];
        int move = route[2] - '0';  // 문자 가져온 것을 숫자로 변환 해야함
        bool CanGo = true;

        
        if(direction == 'E'){
            for(int i = 1; i <= move; i++){
                if(StartX + i >= ParkWidth){
                    CanGo = false;
                    break;
                }
                if(park[StartY][StartX + i] == 'X'){
                    CanGo = false;
                    break;
                }
            }
            if(CanGo){
                StartX = StartX + move;
            }
        }
        else if(direction == 'W'){
            for(int i = 1; i <= move; i++){
                if(StartX - i < 0){
                    CanGo = false;
                    break;
                }
                if(park[StartY][StartX - i] == 'X'){
                    CanGo = false;
                    break;
                }
            }
            if(CanGo){
                StartX = StartX - move;
            }
        }
        else if(direction == 'S'){
            for(int i = 1; i <= move; i++){
                if(StartY + i >= ParkHeight){
                    CanGo = false;
                    break;
                }
                if(park[StartY + i][StartX] == 'X'){;
                    CanGo = false;
                    break;
                }
            }
            if(CanGo){
                StartY = StartY + move;
            }
        }
        else if(direction == 'N'){
            for(int i = 1; i <= move; i++){
                if(StartY - i < 0){
                    CanGo = false;
                    break;
                }
                if(park[StartY - i][StartX] == 'X'){
                    CanGo = false;
                    break;
                }
            }
            if(CanGo){
                StartY = StartY - move;
            }
        }
    }
    
    answer.push_back(StartY);
    answer.push_back(StartX);
    
    return answer;
}