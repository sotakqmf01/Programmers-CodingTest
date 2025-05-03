#include <string>
#include <vector>
#include <cmath>

using namespace std;

//class Pos{
//public:
//    Pos(int initX, int initY) : x(initX), y(initY) {}
//    
//    int x = 0;
//    int y = 0;
//};

struct Pos{
    Pos(int initX, int initY) : x(initX), y(initY) {}
    
    int x = 0;
    int y = 0;
};

int ManDist(Pos p1, Pos p2){
    return abs(p2.x - p1.x) + abs(p2.y - p1.y);
}

int CheckRoom(vector<Pos>& people, vector<string>& place){
    // 애초에 한 명인 경우나, 다 체크하고 한 명만 남은 상황이면 이미 앞서 체크를 했기 때문에 문제 없음
    while(people.size() > 1){
        // 제일 뒤에서부터 체크
        Pos currPos = people[people.size()-1];

        for(int i = people.size() - 2; i >= 0; i--){
            int dist = ManDist(currPos, people[i]);
            
            // 맨해튼 거리가 1인 경우는 거리두기 x
            if(dist == 1){
                return 0;
            }
            else if(dist == 2){
                // x의 차가 2 or y의 차가 2인 경우
                if(abs(people[i].x - currPos.x) == 2){
                    if(place[(people[i].x + currPos.x) / 2][currPos.y] != 'X')
                        return 0;
                }
                else if(abs(people[i].y - currPos.y) == 2){
                    if(place[currPos.x][(people[i].y + currPos.y) / 2] != 'X')
                        return 0;
                }
                // 대각선에 위치
                else{
                    if(!(place[currPos.x][people[i].y] == 'X' && place[people[i].x][currPos.y] == 'X'))
                        return 0;
                }
            }
        }

        people.erase(people.end()-1);
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<Pos> people;
    
    for(vector<string>& place : places){
        people.clear();
        
        // 각 방에 대한 사람들 위치 저장        
        for(int i = 0; i<place.size(); i++){
            for(int j = 0; j<5; j++){
                if(place[i][j] == 'P'){
                    people.emplace_back(i, j);
                }
            }
        }
        
        answer.push_back(CheckRoom(people, place));
    }
     
    return answer;
}