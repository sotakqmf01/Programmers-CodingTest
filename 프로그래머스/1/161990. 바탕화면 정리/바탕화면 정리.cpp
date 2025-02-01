#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = wallpaper.size();
    int maxX = 0;
    int minY = wallpaper[0].size();
    int maxY = 0;
    
    for(int i = 0; i < (int)wallpaper.size(); i++)
    {
        for(int j = 0; j < (int)wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(j < minY) minY = j;
                if(j > maxY) maxY = j;
                if(i < minX) minX = i;
                if(i > maxX) maxX = i;
            }
        }
    }
    
    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX+1);
    answer.push_back(maxY+1);    
    
    return answer;
}