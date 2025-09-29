#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//int solution(vector<string> want, vector<int> number, vector<string> discount) {
//    int answer = 0;
//    unordered_map<string, int> umap;
//    
//    // 첫 할인 품목 10개 중 각 제품의 개수
//    for(int i = 0; i < 10; i++)
//    {
//        umap[discount[i]]++;
//    }
//        
//    // [첫날 ~ n-10째날]까지 열흘에 대해 체크
//    for(int i = 0; i <= discount.size()-10; i++)
//    {
//        // 제품 수가 같은 경우
//        if(umap.size() == want.size())
//        {
//            bool bIsMembership = true;
//            
//            // 원하는 제품들이 원하는 개수만큼 있는지
//            for(int j = 0; j < umap.size(); j++)
//            {
//                if(umap[want[j]] != number[j])
//                {
//                    bIsMembership = false;
//                    break;
//                }
//            }
//            
//            if(bIsMembership)
//            {
//                answer++;
//            }
//        }
//        
//        // 마지막 날에는 최신화 안하도록
//        if(i < discount.size()-10)
//        {
//            // umap을 다음날에 대한 열흘치 품목으로 최신화
//            if(umap[discount[i]] == 1)
//            {
//                umap.erase(discount[i]);
//                umap[discount[i+10]]++;
//            }
//            else
//            {
//                umap[discount[i]]--;
//                umap[discount[i+10]]++;
//            }
//        } 
//    }
//    
//    return answer;
//}


int solution(vector<string> want, vector<int> number, vector<string> discount){
    int answer = 0;
        
    // 가능한 모든 일수를 찾아야함 => 브루트포스
    // - 매번 10일치 계산하는 것보다 10일치 계산하고, 첫날 품목 빼고, 다음날 품목 추가하는 게 나을 듯
    queue<string> q_discount;
    unordered_map<string, int> um_discount;
    for(int i = 0; i < 10; i++){
        q_discount.push(discount[i]);
        um_discount[discount[i]]++;
    }
    
    for(int i = 9; i < discount.size(); i++){
        // 비교
        bool bCanBuy = true;
        for(int i = 0; i < want.size(); i++){
            if(um_discount[want[i]] != number[i]){
                bCanBuy = false;
                break;
            }
        }
        
        if(bCanBuy)
            answer++;
        
        // 다음날 계산
        if(i == discount.size() - 1)
            break;
        
        string product = q_discount.front();
        q_discount.pop();
        um_discount[product]--;
        
        q_discount.push(discount[i + 1]);
        um_discount[discount[i + 1]]++;
    }
    
    return answer;
}