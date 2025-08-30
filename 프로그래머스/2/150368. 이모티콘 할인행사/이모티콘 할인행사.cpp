#include <string>
#include <vector>

using namespace std;

// 유저별 총 구매액 계산
//void CalculateUserPurchase(vector<int>& sales, const vector<vector<int>>& users, const vector<int>& emoticons, vector<int>& userPurchase){
//    userPurchase = vector(users.size(), 0);
//    
//    vector<int> discountedPrice(sales.size(), 0);   // 할인된 가격
//    for(int i = 0; i < sales.size(); i++){
//        discountedPrice[i] = (emoticons[i] * (100 - sales[i])/100);
//    }
//    
//    for(int i = 0; i < users.size(); i++){
//        for(int j = 0; j < sales.size(); j++){
//            if(sales[j] >= users[i][0]){
//                userPurchase[i] += discountedPrice[j]; 
//            }
//            
//            // 유저의 구매 기준에서 [가격]을 넘은 경우는 남은 이모티콘 구매 계산 X
//            if(userPurchase[i] >= users[i][1]){
//                break;
//            }
//        }
//    }
//}
//
//void CalculateResult(const vector<vector<int>>& users, const vector<int>& userPurchase, vector<int>& answer){
//    vector<int> tempResult = {0, 0};
//    
//    for(int i = 0; i < users.size(); i++){
//        if(userPurchase[i] >= users[i][1])
//            tempResult[0]++;
//        else
//            tempResult[1] += userPurchase[i];
//    }
//    
//    // 할인 행사 목표 비교
//    if(answer[0] < tempResult[0]){
//        answer = tempResult;
//    }
//    else if(answer[0] == tempResult[0]){
//        if(answer[1] <= tempResult[1])
//            answer = tempResult;
//    }
//}
//
//void dfs(int depth, vector<int>& sales, const vector<vector<int>>& users, const vector<int>& emoticons, vector<int>& userPurchase, vector<int>& answer){
//    if(depth == emoticons.size()){
//        return;
//    }
//    
//    vector<int> salePercent = {10, 20, 30, 40};
//        
//    for(int i = 0; i < salePercent.size(); i++){
//        sales[depth] = salePercent[i];
//        
//        if(depth == emoticons.size() - 1){
//            CalculateUserPurchase(sales, users, emoticons, userPurchase);        
//            CalculateResult(users, userPurchase, answer);
//         }
//        
//        dfs(depth + 1, sales, users, emoticons, userPurchase, answer);
//    }
//}
//
//vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
//    vector<int> answer = {0, 0};
//    vector<int> sales(emoticons.size(), 0); // 이모티콘 별 할인율
//    vector<int> userPurchase(users.size(), 0);  // 각 사용자 별 총 구매액
//    
//    dfs(0, sales, users, emoticons, userPurchase, answer);
//    
//    return answer;
//}


// 다른 사람 풀이
int max_user = -1;
int max_value = -1;
int discounts[7];
vector<int> answer(2, 0);

void getComb(int pos, vector<vector<int>> &users, vector<int> &emoticons) {
    if (pos == emoticons.size()) {
        int total_price = 0;
        int total_user = 0;

        for (int i = 0; i < users.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < emoticons.size(); j++) {
                if (discounts[j] >= users[i][0])
                    tmp += emoticons[j] * (100 - discounts[j]) / 100;
            }

            if (tmp >= users[i][1]) total_user++;
            else total_price += tmp;
        }

        answer = max(answer, {total_user, total_price});
        return;
    }

    for (int i = 1; i <= 4; i++) {
        discounts[pos] = i * 10;
        getComb(pos + 1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    getComb(0, users, emoticons);
    return answer;
}