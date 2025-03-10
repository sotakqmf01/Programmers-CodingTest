#include <string>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // records를 순회하면서 <차량, 누적 주차 시간>, <차량, 내역>  저장
    // - 내역에 따라 입/출차 확인
    // - 누적 주차 시간 저장
    map<string, int> CarNTimes;
    map<string, string> CarNHistories;
    vector<string> CarNum;  // 차량 번호가 작은 자동차부터 => 오름차순
    
    istringstream iss;
    string Time;
    string Car;
    string History;
    
    for(const string& record : records)
    {
        iss.str(record);
        iss >> Time >> Car >> History;
        
        CarNHistories[Car] = History;
        if(History == "IN")
        {
            CarNTimes[Car] -= stoi(Time.substr(0,2)) * 60 + stoi(Time.substr(3,2));
        }
        else
        {
            CarNTimes[Car] += stoi(Time.substr(0,2)) * 60 + stoi(Time.substr(3,2));
        }
        
        CarNum.push_back(Car);
        
        // iss 다시 쓸려면 clear() 해야함
        iss.clear();
    }
    
    // 내역이 입차로 끝난 차들에 대해 23:59에 출차시키기
    for(const pair<string, string>& CarNHistory : CarNHistories)
    {
        if(CarNHistory.second == "IN")
        {
            CarNTimes[CarNHistory.first] += 23 * 60 + 59;
        }
    }
    
    // 차 번호 오름차순
    sort(CarNum.begin(), CarNum.end());
    
    vector<string>::iterator it = unique(CarNum.begin(), CarNum.end());
    CarNum.erase(it, CarNum.end());
    
    // 요금 = fees[1] + ceil(((누적 주차 시간) - fees[0]) / fees[2]) * fees[3];
    for(int i = 0; i < CarNum.size(); i++)
    {
        if(CarNTimes[CarNum[i]] >= fees[0])
        {
            answer.push_back(fees[1] + ceil((float)(CarNTimes[CarNum[i]] - fees[0]) / fees[2]) * fees[3]);
        }
        else
        {
            answer.push_back(fees[1]);
        }
    }
        
    return answer;
}