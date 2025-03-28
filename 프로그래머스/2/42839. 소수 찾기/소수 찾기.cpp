#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

vector<bool> visited;
int answer = 0;

bool IsPrime(int num)
{
    if(num < 2)
    {
        return false;
    }
    
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

void DFS(const string& nextNumStr, const string& numbers, set<string>& numStrSet, set<int>& numSet)
{
    if(nextNumStr != "")
    {
        if(numStrSet.find(nextNumStr) != numStrSet.end())
        {
            return;
        }
        
        numStrSet.emplace(nextNumStr);
        
        int num = stoi(nextNumStr);
        if(numSet.find(num) == numSet.end())
        {
            numSet.emplace(num);
            
            if(IsPrime(num))
            {
                answer++;
            }
        }
    }
    
    for(int i = 0; i < numbers.length(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            DFS(nextNumStr + numbers[i], numbers, numStrSet, numSet);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    // numbers = {0 1 2 1 3}일 때, "013"을 만드는 경우가
    // idx = 0 1 4 or 0 3 4 이렇게 두 가지가 생김
    set<string> numStrSet;  // 문자열이 중복되는 경우를 제외
    // 11이 나오는 경우가
    // idx = 0 1 3("011") or 1 3("11") 이렇게 두 가지가 있음
    set<int> numSet;    // 문자열을 숫자로 바꿨을 때 중복되는 경우를 제외
    visited = vector<bool>(numbers.length(), false);
    
    DFS("", numbers, numStrSet, numSet);
    
    return answer;
}