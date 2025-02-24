#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> umap;
    
    // 첫 할인 품목 10개 중 각 제품의 개수
    for(int i = 0; i < 10; i++)
    {
        umap[discount[i]]++;
    }
        
    // 첫날 ~ n-10째날까지 열흘에 대해 체크
    for(int i = 0; i <= discount.size()-10; i++)
    {
        // 제품 수가 같은 경우
        if(umap.size() == want.size())
        {
            bool bIsMembership = true;
            
            // 원하는 제품들이 원하는 개수만큼 있는지
            for(int j = 0; j < umap.size(); j++)
            {
                if(umap[want[j]] != number[j])
                {
                    bIsMembership = false;
                    break;
                }
            }
            
            if(bIsMembership)
            {
                answer++;
            }
        }
        
        // 마지막 날에는 최신화 안하도록
        if(i < discount.size()-10)
        {
            // umap을 다음날에 대한 열흘치 품목으로 최신화
            if(umap[discount[i]] == 1)
            {
                umap.erase(discount[i]);
                umap[discount[i+10]]++;
            }
            else
            {
                umap[discount[i]]--;
                umap[discount[i+10]]++;
            }
        } 
    }
    
    return answer;
}