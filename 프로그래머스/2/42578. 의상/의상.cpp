#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> NumberByTypes;
    vector<string> clothesType;

    // 얼굴 : [안입음, 동그란 안경, 검정 선글라스]
    // 상의 : [안입음, 파란색 티셔츠]
    // 하의 : [안입음, 청바지]
    // 입지 않을때 1을 더해서 조합을 구하면 구해진 조합 내에서 (안입음, 안입음, 청바지), (안입음, 파란색 티셔츠, 청바지) 
    // 이런식 으로도 조합이 되기 때문에 하나만 입을 때, 두개 입을 때, ... 을 다 구해줍니다
    // 대신 (안입음, 안입음, 안입음) 이런 조합도 나올 수 있기 때문에 1을 빼주는거예요
    for (int i = 0; i < clothes.size(); i++)
    {
        NumberByTypes[clothes[i][1]]++;
    }

    for (const pair<string, int>& NumberByType : NumberByTypes)
    {
        // 안입는 경우를 포함하기 위해 +1 하여 경우의 수 곱하기
        answer *= NumberByType.second + 1;
    }

    // 아무것도 안입은 경우는 제외
    answer -= 1;
    
    //int answer = 0;
    //
    //// 종류별 의상 수
    //for(int i = 0; i < clothes.size(); i++)
    //{
    //    NumberByTypes[clothes[i][1]]++;
    //    if(find(clothesType.begin(), clothesType.end(), clothes[i][1]) == clothesType.end())
    //    {
    //        clothesType.push_back(clothes[i][1]);
    //    }
    //}
    //
    //// 1종류만 착용 ~ 모든 종류 전부 착용
    //for(int i = 0; i < NumberByTypes.size(); i++)
    //{
    //    vector<int> combi(NumberByTypes.size(),0);
    //    fill(combi.end() - (i+1), combi.end(), 1);
    //    
    //    // n종류 착용 시 조합
    //    do{
    //        int NumberOfCases = 1;
    //        
    //        for(int j = 0; j < combi.size(); j++)
    //        {
    //            if(combi[j] == 1)
    //            {
    //                NumberOfCases *= NumberByTypes[clothesType[j]];
    //            }
    //        }
    //        
    //        answer += NumberOfCases;
    //    }while(next_permutation(combi.begin(), combi.end()));
    //}
    
    return answer;
}