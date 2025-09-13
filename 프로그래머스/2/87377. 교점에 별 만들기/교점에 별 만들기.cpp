#include <string>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long>> intersectionPoints;
    long long minX = LLONG_MAX;
    long long maxX = LLONG_MIN;
    long long minY = LLONG_MAX;
    long long maxY = LLONG_MIN;
    
    // 교점 구하기
    for(int i = 0; i < line.size() - 1; i++){
        long long A = line[i][0];
        long long B = line[i][1];
        long long E = line[i][2];
        
        for(int j = i+1; j < line.size(); j++){
            long long C = line[j][0];
            long long D = line[j][1];
            long long F = line[j][2];
            
            long long denominator = A*D - B*C;
            if(denominator != 0){
                double x = (double)(B*F - E*D) / denominator;
                double y = (double)(E*C - A*F) / denominator;
                
                // 정수 좌표
                if((B*F - E*D) % denominator == 0 && (E*C - A*F) % denominator == 0){
                    intersectionPoints.emplace_back((long long)x, (long long)y);
                    
                    if(x < minX)
                        minX = (long long)x;
                    if(x > maxX)
                        maxX = (long long)x;
                    if(y < minY)
                        minY = (long long)y;
                    if(y > maxY)
                        maxY = (long long)y;
                }
            }
        }
    }
    
    // 사각형 그리기    
    answer.assign(maxY - minY + 1, string(maxX - minX + 1, '.'));
    
    // (좌표 -> 배열 인덱스) 변환
    for(const pair<long long, long long>& point : intersectionPoints){
        answer[maxY - point.second][point.first - minX] = '*';
    }
    
    return answer;
}