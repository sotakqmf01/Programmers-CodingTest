#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

//struct task{
//    task() : name(""), startTime(0), playTime(0) {}
//    task(string _name, int _startTime, int _playTime) : name(_name), startTime(_startTime), playTime(_playTime) {}
//    
//    string name;
//    int startTime;
//    int playTime;
//};
//
//struct compare{
//    bool operator()(const task& plan1, const task& plan2){
//        return plan1.startTime > plan2.startTime;
//    }
//};
//
//// 시간을 int형으로 변환
//int getStart(const string& startTime_string){
//    int startTime_int = 0;
//    
//    startTime_int = stoi(startTime_string.substr(0,2)) * 60 + stoi(startTime_string.substr(3,2));
//    
//    return startTime_int;
//}
//
//vector<string> solution(vector<vector<string>> plans) {
//    vector<string> answer;
//    priority_queue<task, vector<task>, compare> start_pq;    // 전체 과제를 시작 순서를 기준으로 넣을 우선순위 큐
//    stack<task> pause_st;  // 잠시 멈춘 과제를 넣을 스택
//    
//    // 과제 시작 시간 순서 정렬
//    for(const vector<string>& temp_plan : plans){
//        task plan = task(temp_plan[0], getStart(temp_plan[1]), stoi(temp_plan[2]));
//        
//        start_pq.push(plan);
//    }
//        
//    // 다음 과제를 할 때는 새로운 과제 -> 진행 중이던 과제
//    // - 처음 시작할 때만 시작 시각이 중요
//    // - 이후로는 가장 최근에 중단된 과제부터 시작
//    int next = 0;   // 0이면 start_pq에서 다음 과제, 1이면 pause_st에서 다음 과제
//    int currentTime = 0;   // ★ 중단했다가 다시 시작하는 과제들의 시작시간을 알기 위해 필요
//    while(!(start_pq.empty() && pause_st.empty())){
//        task currentPlan;
//        if(next){
//            currentPlan = pause_st.top();
//            currentPlan.startTime = currentTime;
//            pause_st.pop();
//        }else{
//            currentPlan = start_pq.top();
//            start_pq.pop();
//        }
//        
//        // 새로운 과제가 아직 남아 있으면, 다음에 해야할 과제를 찾아야함
//        if(!start_pq.empty()){
//            int startTimeOfNextPlan = start_pq.top().startTime;
//            
//            // 다음에 새로운 과제를 시작할 지 or 중단된 과제를 시작할 지
//            if(startTimeOfNextPlan <= currentPlan.startTime + currentPlan.playTime){
//                next = 0;
//                    
//                // 현재 과제를 진행하는 중간에 새로운 과제를 해야함
//                // - 현재 과제를 멈춘 과제 queue에 넣어야함
//                currentPlan.playTime -= startTimeOfNextPlan - currentPlan.startTime;
//                if(currentPlan.playTime != 0)
//                    pause_st.push(currentPlan);
//            }
//            else{
//                // - 현재 진행하고 있는 과제를 끝냈을 때 다음 새로운 과제를 시작할 시간이 안되었으면, 중단된 과제를 시작해야함
//                // - ★ 중단된 과제가 없으면, 새로운 과제를 시작해야함
//                if(!pause_st.empty())
//                    next = 1;
//                else
//                    next = 0;
//                
//                currentTime = currentPlan.startTime + currentPlan.playTime; // ★ 중단했다가 다시 시작하는 과제의 시작 시간을 알기 위해
//                currentPlan.playTime = 0;   // ★ 과제를 끝냈으니 playTime을 0으로 만들어야함
//            }
//                
//            // 과제 완료
//            if(currentPlan.playTime <= 0){
//                answer.push_back(currentPlan.name);
//            }
//            
//        }else{
//            // 새로운 과제가 없으면, 현재 하는 과제를 끝내고 멈춘 과제를 뒤에서부터 순서대로 하면 됨.
//            // - 여기선 굳이 시간 계산을 할 필요 없음.
//            // - 왜? 멈춰둔 과제들은 그냥 뒤에서부터 순서대로 끝내기 때문
//            next = 1;
//            answer.push_back(currentPlan.name);
//        }
//    }
//    
//    // 다음 과제와 현재 과제의 playtime을 비교해야함
//    return answer;
//}

// ChatGPT 코드
static int ToMinutes(const string& timeString) {
    return stoi(timeString.substr(0, 2)) * 60 + stoi(timeString.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    // 시작 시각 기준 정렬
    sort(plans.begin(), plans.end(),
         [](const vector<string>& plan1, const vector<string>& plan2) {
             return ToMinutes(plan1[1]) < ToMinutes(plan2[1]);
         });

    vector<string> answer;
    stack<pair<string, int>> paused_st; // (과제 이름, 남은 시간)

    for (int i = 0; i < (int)plans.size(); ++i) {
        int currentStartTime = ToMinutes(plans[i][1]);
        string currentName = plans[i][0];
        int currentPlayTime = stoi(plans[i][2]);

        int nextStartTime = (i + 1 < plans.size()) ? ToMinutes(plans[i + 1][1]) : INT_MAX; // 마지막 과제면 제한 없음
        int gap = nextStartTime - currentStartTime;

        // 현재 과제 시작
        paused_st.push({currentName, currentPlayTime});

        // 다음 과제 시작 전까지 남은 시간 동안, 멈춘 과제들을 LIFO로 진행
        while (gap > 0 && !paused_st.empty()) {
            auto [top_name, top_playTime] = paused_st.top();
            paused_st.pop();

            if (top_playTime <= gap) {
                gap -= top_playTime;
                answer.push_back(top_name); // 과제 완료
            } else {
                top_playTime -= gap;
                gap = 0;
                paused_st.push({top_name, top_playTime}); // 아직 남은 시간 있음
            }
        }
    }

    // 남아 있는 과제 마무리
    while (!paused_st.empty()) {
        answer.push_back(paused_st.top().first);
        paused_st.pop();
    }

    return answer;
}