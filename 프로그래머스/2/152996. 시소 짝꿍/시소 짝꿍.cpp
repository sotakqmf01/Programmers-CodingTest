#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool CanPair(int weight1, int weight2){
    if(weight1 > weight2)
        swap(weight1, weight2);
    
    if(weight1 * 2 == weight2 * 2)
        return true;
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
    vector<int> copyOfWeights = weights;
    map<long long, int> countOfSameWeight;    // 같은 몸무게를 가지는 사람의 수
    map<long long, int> countOfPair;    // 다른 몸무게를 가지는 사람 중 짝꿍 수(중복 X)
    
    sort(copyOfWeights.begin(), copyOfWeights.end());
    vector<int>::iterator it = unique(copyOfWeights.begin(), copyOfWeights.end());
    copyOfWeights.erase(it, copyOfWeights.end());
    
    // 같은 몸무게를 가지는 사람 수 구하기
    for(int weight : weights){
        countOfSameWeight[weight]++;
    }
    
    for(int weight : copyOfWeights){
        countOfPair[weight] = 0;
    }
    
    // 같은 몸무게를 가진 사람들의 조합 수 = n * (n - 1) / 2
    for(const pair<long long, int>& sameWeight : countOfSameWeight){
        long long combi = (long long)sameWeight.second * (sameWeight.second - 1) / 2;
        answer += combi;
        //cout << "weight : " << sameWeight.first << ", count : " << sameWeight.second << endl;
    }
        
    // 다른 몸무게를 가진 사람과의 짝꿍 수
    for(int i = 0; i < copyOfWeights.size()-1; i++){
        for (int j = i + 1; j < copyOfWeights.size(); j++){
            if(CanPair(copyOfWeights[i], copyOfWeights[j])){
                //cout << "[" << copyOfWeights[i] << "," << copyOfWeights[j] << "] " << "Can Pair" << endl;
                countOfPair[copyOfWeights[i]] += countOfSameWeight[copyOfWeights[j]];
            }
        }
        //cout << "countOfPair[" << copyOfWeights[i] << "] : " << countOfPair[copyOfWeights[i]] << endl;
    }
    
    for(int i = 0; i < copyOfWeights.size(); i++){
        answer += countOfPair[copyOfWeights[i]] * countOfSameWeight[copyOfWeights[i]];
    }
    
    return answer;
}