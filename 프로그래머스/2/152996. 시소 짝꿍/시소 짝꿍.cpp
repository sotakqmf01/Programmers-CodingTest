#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

//bool CanPair(int weight1, int weight2){
//    if(weight1 > weight2)
//        swap(weight1, weight2);
//    
//    if(weight1 * 2 == weight2 * 2)
//        return true;
//    else if(weight1 * 3 == weight2 * 2)
//        return true;
//    else if(weight1 * 4 == weight2 * 2)
//        return true;
//    else if(weight1 * 4 == weight2 * 3)
//        return true;
//    else
//        return false;
//}
//
//long long solution(vector<int> weights) {
//    long long answer = 0;
//    vector<int> copyOfWeights = weights;
//    map<long long, int> countOfSameWeight;    // 같은 몸무게를 가지는 사람의 수
//    map<long long, int> countOfPair;    // 다른 몸무게를 가지는 사람 중 짝꿍 수(중복 X)
//    
//    sort(copyOfWeights.begin(), copyOfWeights.end());
//    vector<int>::iterator it = unique(copyOfWeights.begin(), copyOfWeights.end());
//    copyOfWeights.erase(it, copyOfWeights.end());
//    
//    // 같은 몸무게를 가지는 사람 수 구하기
//    for(int weight : weights){
//        countOfSameWeight[weight]++;
//    }
//    
//    for(int weight : copyOfWeights){
//        countOfPair[weight] = 0;
//    }
//    
//    // 같은 몸무게를 가진 사람들의 조합 수 = n * (n - 1) / 2
//    for(const pair<long long, int>& sameWeight : countOfSameWeight){
//        long long combi = (long long)sameWeight.second * (sameWeight.second - 1) / 2;
//        answer += combi;
//        //cout << "weight : " << sameWeight.first << ", count : " << sameWeight.second << endl;
//    }
//        
//    // 다른 몸무게를 가진 사람과의 짝꿍 수
//    for(int i = 0; i < copyOfWeights.size()-1; i++){
//        for (int j = i + 1; j < copyOfWeights.size(); j++){
//            if(CanPair(copyOfWeights[i], copyOfWeights[j])){
//                //cout << "[" << copyOfWeights[i] << "," << copyOfWeights[j] << "] " << "Can Pair" << endl;
//                countOfPair[copyOfWeights[i]] += countOfSameWeight[copyOfWeights[j]];
//            }
//        }
//        //cout << "countOfPair[" << copyOfWeights[i] << "] : " << countOfPair[copyOfWeights[i]] << endl;
//    }
//    
//    for(int i = 0; i < copyOfWeights.size(); i++){
//        answer += countOfPair[copyOfWeights[i]] * countOfSameWeight[copyOfWeights[i]];
//    }
//    
//    return answer;
//}

// 다른 사람 풀이
//long long solution(vector<int> weights) {
//    long long answer = 0; // 시소 짝꿍 쌍의 개수를 저장할 변수 초기화
//    
//    sort(weights.begin(), weights.end()); // 몸무게 목록을 오름차순으로 정렬
//
//    // 이중 반복문을 사용하여 가능한 모든 몸무게 쌍을 비교
//    for(int i = 0; i < weights.size(); i++)
//    {
//        for(int j = i + 1; j < weights.size(); j++)
//        {
//            // 두 사람의 몸무게가 같은 경우
//            if(weights[i] == weights[j])
//            {
//                answer++; // 시소 짝꿍 쌍의 개수 증가
//            }
//            // 몸무게 비율이 2:3인 경우 (2m, 3m 좌석)
//            else if(weights[i] * 3 == weights[j] * 2)
//            {
//                answer++; // 시소 짝꿍 쌍의 개수 증가
//            }
//            // 몸무게 비율이 3:4인 경우 (3m, 4m 좌석)
//            else if(weights[i] * 4 == weights[j] * 3)
//            {
//                answer++; // 시소 짝꿍 쌍의 개수 증가
//            }
//            // 몸무게 비율이 1:2인 경우 (2m, 4m 좌석)
//            else if(weights[i] * 2 == weights[j])
//            {
//                answer++; // 시소 짝꿍 쌍의 개수 증가
//            }
//            // 현재 몸무게의 2배를 초과하는 몸무게가 나오면 더 이상 비교할 필요가 없음
//            else if(weights[i] * 2 < weights[j])
//                break; // 내부 반복문 종료
//        }
//    }
//    
//    return answer; // 시소 짝꿍 쌍의 총 개수 반환
//}

long long solution(vector<int> weights) {
    long long answer = 0;

    vector<long long> arr(2001,0);

    for(const auto v : weights)
    {
        arr[v]++;
    }

    for(int i = 100; i <= 1000; ++i)
    {
        if(arr[i] == 0)
        {
            continue;
        }

        answer += arr[i]*(arr[i]-1) / 2;

        answer += arr[i] * arr[2 * i];

        if((i * 3) % 2 == 0)
        {
            answer += arr[i] * arr[i * 3 / 2];
        }

        if((i * 4) % 3 == 0)
        {
            answer += arr[i] * arr[i * 4 / 3];
        }   
    }

    return answer;
}