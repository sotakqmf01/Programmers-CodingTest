#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int monthDays[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int days = b;
    
    for(int i = 1; i < a; i++)
    {
        days += monthDays[i-1];
    }
    
    answer = day[days%7];
    
    return answer;
}