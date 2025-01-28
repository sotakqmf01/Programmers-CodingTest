#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int lostFriend : lost)
    {
        // 잃어버렸지만 내가 여벌이 있는 경우
        vector<int>::iterator it = find(reserve.begin(), reserve.end(), lostFriend);
        if(it != reserve.end())
        {
            cout << "i have 여벌" << endl;
            ++answer;
            reserve.erase(it);
        }
        else
        {
            // 여벌이 없는 경우
            // 앞 번호 친구가 여벌이 있는 경우
            it = find(reserve.begin(), reserve.end(), lostFriend-1);
            if(it != reserve.end())
            {
                cout << "-1 friend has 여벌" << endl;
                // 친구도 도난당하지 않은 경우에만 빌려줌
                vector<int>::iterator it2 = find(lost.begin(), lost.end(), lostFriend-1);
                if(it2 == lost.end())
                {
                    ++answer;
                    reserve.erase(it);
                    continue;
                }
            }
            
            // 앞 번호 친구는 여벌이 없고 뒷 번호 친구가 여벌이 있는 경우
            it = find(reserve.begin(), reserve.end(), lostFriend+1);
            if(it != reserve.end())
            {
                cout << "+1 friend has 여벌" << endl;
                // 친구도 도난당하지 않은 경우에만 빌려줌
                vector<int>::iterator it2 = find(lost.begin(), lost.end(), lostFriend+1);
                if(it2 == lost.end())
                {
                    ++answer;
                    reserve.erase(it);
                }
            }
        }
    }
    
    return answer;
}