#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> UserIndex;
    // 각 유저별로 [자신을 신고한 유저들의 이름을 저장]할 벡터
    vector<set<string>> User(id_list.size());
    
    for(int i = 0; i < id_list.size(); i++)
    {
        // 각 유저의 index를 저장
        UserIndex[id_list[i]] = i;
    }
    
    for(const string& str : report)
    {
        int blankPos = str.find(" ");
        string reportingUser = str.substr(0, blankPos);
        string reportedUser = str.substr(blankPos + 1);
        
        // 자신을 신고한 유저 추가
        User[UserIndex[reportedUser]].insert(reportingUser);
    }
    
    for(int i = 0; i < User.size(); i++)
    {
        if(User[i].size() >= k)
        {
            // 신고한 유저들에게 메일 발송
            for(const string& reportingUser : User[i])
            {
                answer[UserIndex[reportingUser]]++;
            }
        }
    }
    
    return answer;
}