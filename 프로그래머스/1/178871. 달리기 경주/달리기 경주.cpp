#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> mRank;
    
    for(int i = 0; i < players.size(); i++)
    {
        mRank[players[i]] = i;
    }
    
    for(const string& called : callings)
    {
        int rank = mRank[called];
        
        swap(players[rank], players[rank - 1]);
        
        mRank[players[rank]] = rank;
        mRank[players[rank - 1]] = rank - 1;
    }
    
    return players;
}