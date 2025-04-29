#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    sort(book_time.begin(), book_time.end());
    for (int i = 0; i < book_time.size(); i++) {
        string st = book_time[i][0];
        string ed = book_time[i][1];
        int stT = stoi(st.substr(0, 2)) * 60 + stoi(st.substr(3));
        int edT = stoi(ed.substr(0, 2)) * 60 + stoi(ed.substr(3)) + 10;
        while (!q.empty() && q.top() <= stT) {
            q.pop();
        }
        q.push(edT);
        answer = max(answer, (int)q.size());
    }
    return answer;
}

//bool Compare(vector<string>& book1, vector<string>& book2){
//    return book1[0] < book2[0];
//}
//
//// 존재하는 방들의 입실 가능 시간을 보면서, 예약 가능한 방을 찾는 함수
//int FindRoom(vector<string> book, vector<int> rooms){
//    int checkInHour = stoi(book[0].substr(0,2));
//    int checkInMin = stoi(book[0].substr(3,2));
//    int checkIn = checkInHour * 60 + checkInMin;
//    
//    for(int i = 0; i<rooms.size(); i++){
//        if(checkIn >= rooms[i])
//            return i;
//    }
//    
//    return -1;
//}
//
//int solution(vector<vector<string>> book_time) {
//    int answer = 0;
//    // 존재하는 방을 표시하는 vector, 입실 가능 시간(퇴실시간 + 10) 저장
//    // - 빈 방이 없을 때마다 추가
//    vector<int> rooms;
//    
//    // 예약 입실시간 기준 정렬
//    sort(book_time.begin(), book_time.end(), Compare);
//    
//    for(vector<string>& book : book_time){
//        int checkOutHour = stoi(book[1].substr(0,2));
//        int checkOutMin = stoi(book[1].substr(3,2));
//        
//        int canBookTime = checkOutHour * 60 + checkOutMin + 10;
//        
//        // 각 방들을 입실 가능 시간(퇴실+10)으로 오름차순 정렬
//        // - (입실 가능-입실) 비교하기 편하게
//        sort(rooms.begin(), rooms.end());
//        
//        int roomIndex = FindRoom(book, rooms);
//        if(roomIndex != -1){
//            // 예약 가능한 방이 존재하는 경우, 갱신
//            rooms[roomIndex] = canBookTime;
//        }
//        else{
//            // 예약 가능한 방이 존재하지 않으면, 추가
//            rooms.push_back(canBookTime);
//        }
//    }
//    
//    return rooms.size();
//}


//int solution(vector<vector<string>> book_time) {
//    int answer = 0;
//    // 존재하는 방을 표시하는 vector, 입실 가능 시간(퇴실시간 + 10) 저장
//    // - 빈 방이 없을 때마다 추가
//    vector<string> rooms;
//    
//    // 예약 입실시간 기준 정렬
//    sort(book_time.begin(), book_time.end(), Compare);
//    
//    for(vector<string>& book : book_time){
//        int checkOutHour = stoi(book[1].substr(0,2));
//        int checkOutMin = stoi(book[1].substr(3,2));
//        checkOutMin += 10;
//        if(checkOutMin >= 60){
//            checkOutMin = checkOutMin - 60;
//            checkOutHour++;
//        }
//
//        // [로직 문제] 
//        // Hour가 01, 02, ..., 09 이런 식이어야하는데,
//        // to_string하면서 그냥 1, 2, ..., 9 가 되어서 비교가 제대로 안됨
//        // => 그냥 시간을 분으로 바꿔서 int로 계산
//        string canBookTime = to_string(checkOutHour) + ":" + to_string(checkOutMin);
//        cout << "Can Check In : " << canBookTime << endl;
//        
//        // 각 방들을 입실 가능 시간(퇴실+10)으로 오름차순 정렬
//        // - (입실 가능-입실) 비교하기 편하게
//        sort(rooms.begin(), rooms.end());
//        
//        int roomIndex = FindRoom(book, rooms);
//        if(roomIndex != -1){
//            // 예약 가능한 방이 존재하는 경우, 갱신
//            rooms[roomIndex] = canBookTime;
//        }
//        else{
//            // 예약 가능한 방이 존재하지 않으면, 추가
//            rooms.push_back(canBookTime);
//        }
//    }
//    
//    return rooms.size();
//}