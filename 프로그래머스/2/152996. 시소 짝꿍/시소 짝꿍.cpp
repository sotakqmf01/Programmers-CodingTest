#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool CanPair(int weight1, int weight2){
    if(weight1 > weight2)
        swap(weight1, weight2);
    
    else if(weight1 * 3 == weight2 * 2)
        return true;
    else if(weight1 * 4 == weight2 * 2)
        return true;
    else if(weight1 * 4 == weight2 * 3)
        return true;
    else
        return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    // 굳이 벡터를 하나 복사하지 않아도 될 듯
    vector<int> copyOfWeights = weights;
    map<long long, int> countOfSameWeight;  // 같은 몸무게를 가지는 사람의 수
    map<long long, int> countOfPair;        // 다른 몸무게를 가지는 사람 중 짝꿍 수(중복 X)
    
    // 같은 몸무게를 가지는 사람 수 구하기
    for(int weight : weights){
        countOfSameWeight[weight]++;
    }
    
    sort(copyOfWeights.begin(), copyOfWeights.end());
    vector<int>::iterator it = unique(copyOfWeights.begin(), copyOfWeights.end());
    copyOfWeights.erase(it, copyOfWeights.end());
    
    for(int weight : copyOfWeights){
        countOfPair[weight] = 0;
    }
    
    // 같은 몸무게를 가진 사람들의 조합 수 = n * (n - 1) / 2
    for(const pair<long long, int>& sameWeight : countOfSameWeight){
        long long combi = (long long)sameWeight.second * (sameWeight.second - 1) / 2;
        answer += combi;
    }
        
    // 다른 몸무게를 가진 사람과의 짝꿍 수
    // - 위에서 unique로 중복 다 지움
    // - [100, 180, 270, 360] : 0,1 비교 / 0,2 비교 / 0,3 비교 / 1,2 비교 / .... / n-1,n 비교
    // - => 이러면 중복으로 짝 비교하지 않을 수 있음
    for(int i = 0; i < copyOfWeights.size()-1; i++){
        for (int j = i + 1; j < copyOfWeights.size(); j++){
            if(CanPair(copyOfWeights[i], copyOfWeights[j])){
                // 비교해서 짝이 가능하면, 같은 몸무게를 가지는 사람 수를 누적
                countOfPair[copyOfWeights[i]] += countOfSameWeight[copyOfWeights[j]];
            }
        }
    }
    
    for(int i = 0; i < copyOfWeights.size(); i++){
        // 몸무게A와 짝꿍 가능한 사람들의 수 * 몸무게A를 가지는 사람 수
        answer += countOfPair[copyOfWeights[i]] * countOfSameWeight[copyOfWeights[i]];
    }
    
    return answer;
}

// 다른 사람 풀이
//long long solution(vector<int> weights) {
//    long long answer = 0;
//
//    vector<long long> arr(2001,0);
//
//    for(const auto v : weights)
//    {
//        arr[v]++;
//    }
//
//    for(int i = 100; i <= 1000; ++i)
//    {
//        if(arr[i] == 0)
//        {
//            continue;
//        }
//
//        answer += arr[i]*(arr[i]-1) / 2;
//
//        // 4m:2m인 경우(2:4인 경우는 생각하지 않아도 됨)
//        // - for문으로 몸무게를 작은 값에서부터 큰 값으로 가면서 체크하기 때문
//        // - 몸무게가 i인 사람 수 * 몸무게가 2i인 사람 수
//        answer += arr[i] * arr[2 * i];
//
//        // 3m:2m인 경우
//        if((i * 3) % 2 == 0)
//        {
//            answer += arr[i] * arr[i * 3 / 2];
//        }
//
//        // 4m:3m인 경우
//        if((i * 4) % 3 == 0)
//        {
//            answer += arr[i] * arr[i * 4 / 3];
//        }   
//    }
//
//    return answer;
//}