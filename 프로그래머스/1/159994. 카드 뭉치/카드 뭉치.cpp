#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {      
    int idx1 = 0;
    int idx2 = 0;

    // && idx1 < idx2 + 1 
    // && idx2 < idx1 + 1 
    for(string& goalStr : goal){
        if(cards1[idx1] == goalStr && idx1 < cards1.size())
            idx1++;
        else if(cards2[idx2] == goalStr && idx2 < cards2.size())
            idx2++;
        else
            return "No";
    }
    
    return "Yes";  
  
    
    //string answer = "";
    //string answer2 = "";
    //string goalStr = "";
    //
    //for(int i = cards1.size(); i < 10; i++)
    //    cards1.push_back("");
    //for(int i = cards2.size(); i < 10; i++)
    //    cards1.push_back("");
    //for(int i = 0; i < goal.size(); i++)
    //    goalStr += goal[i];
    //
    //for(int i = 0; i<10; i++){
    //    answer += cards1[i] + cards2[i];
    //    answer2 += cards2[i] + cards1[i];
    //    
    //    int length = answer.length() < goalStr.length() ? answer.length() : goalStr.length();
    //    
    //    if(answer.compare(0, answer.length(), goalStr, 0, answer.length())==0){
    //        answer2 = answer;
    //    }
    //    else if(answer2.compare(0, answer2.length(), goalStr, 0, answer2.length())==0){
    //        answer = answer2;
    //    }
    //    else{
    //        return "No";
    //    }
    //}
    //
    //return "Yes";
}