#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0){
        int floor = storey % 10;
        storey /= 10;
        
        if(floor < 5){
            answer += abs(-floor);
        }
        else if(floor > 5){
            answer += 10 - floor;
            storey++;
        }
        else
        {
            if(storey % 10 >= 5){
                answer += 5;
                storey++;
            }
            else{
                answer += abs(-5);
            }
        }
    }
    
    return answer;
}