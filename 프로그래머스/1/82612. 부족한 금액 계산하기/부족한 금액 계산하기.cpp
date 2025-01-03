using namespace std;

long long solution(int price, int money, int count)
{
    long long accum = 0;
    
    for(int i = 1; i <= count; i++){
        accum = accum + (price * i);
    }
    
    if(accum > money)
            return accum - money;

    return 0;
}