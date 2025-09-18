#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 첫 풀이 : [4~10] 시간 초과
//void CantorLike(string& startBits, int depth, int n){
//    if(depth >= n)
//        return;
//    
//    // 치환 과정
//    for(int i = startBits.length() - 1; i >= 0; i--){
//        if(startBits[i] == '1')
//            startBits.replace(i, 1, "11011");
//        else
//            startBits.replace(i, 1, "00000");
//    }
//        
//    CantorLike(startBits, depth+1, n);
//}
//
//int solution(int n, long long l, long long r) {
//    int answer = 0;
//    string cantorBits = "1";
//    
//    CantorLike(cantorBits, 0, n);
//    
//    answer = count_if(cantorBits.begin() + l - 1, cantorBits.begin() + r, [](const char ch){return ch == '1';});
//        
//    return answer;
//}

// 참고하기 좋은 블로그
// https://keepgoing0328.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%9E%90%EB%B0%94-%EC%9C%A0%EC%82%AC-%EC%B9%B8%ED%86%A0%EC%96%B4-%EB%B9%84%ED%8A%B8%EC%97%B4
// https://codingjj.tistory.com/209
// https://kne-coding.tistory.com/331
// https://moneygear.tistory.com/4
// https://moneygear.tistory.com/4#google_vignette
// https://sound-programming.tistory.com/203


// 분할 정복 + 재귀 + 수학적 풀이
void CantorLike(long long index, int n, long long& count){
    if(index <= 0)
        return;
    if(n == 1){
        count += (index >= 3) ? index - 1 : index;
        return;
    }
    
    long long part = index / (long long)pow(5, n-1);         // 몫 : 실제 현재 구간 = part + 1 (5는 그냥 5)
    long long nextIndex = index % (long long)pow(5, n-1);    // 나머지 : 현재 구간에서의 index
    
    count += (part >= 3) ? (part - 1) * (long long)pow(4, n-1) : part * (long long)pow(4, n-1);
    
    if(part == 2)
        return;
    
    CantorLike(nextIndex, n-1, count);
}

int solution(int n, long long l, long long r){
    long long rCount = 0;
    long long lCount = 0;
    
    CantorLike(r, n, rCount);
    CantorLike(l-1, n, lCount);
    
    return rCount - lCount;
}