using namespace std;

//long long solution(int price, int money, int count)
//{
//    long long accum = 0;
//    
//    for(int i = 1; i <= count; i++){
//        accum = accum + (price * i);
//    }
//    
//    if(accum > money)
//            return accum - money;
//
//    return 0;
//}


long long solution(int price, int money, int count){
    long long answer = 0;
    
    long long times = (count + 1) * count / 2;
    
    answer = times * price - money;
    if(answer < 0)
        answer = 0;
    
    return answer;
}