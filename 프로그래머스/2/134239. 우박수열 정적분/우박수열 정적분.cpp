#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int collatz(int k, vector<int>& hail){
    int n = 0;
    hail.push_back(k);
                                      
    while(k != 1){
        if(k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;

        hail.push_back(k);
        n++;
    }
    
    return n;
}

double Integral(int a, int b, const vector<int>& hail){
    double area = 0.0;
    
    for(int i = a; i < b; i++){
        // 각 구간의 x값의 차이는 1
        area += abs(hail[i] - hail[i+1]) * 1 * 0.5 + min(hail[i], hail[i+1]) * 1;
    }
    cout << "area :  " << area << endl;
    
    return area;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> hail;
    // n 구하기
    int n = collatz(k, hail);
    
    // 각 범위에 대한 넓이 구하기
    for(const vector<int>& range : ranges){
        int a = range[0];
        int b = n + range[1];
        
        if(a > b)
            answer.push_back(-1.0);
        else if(a == b)
            answer.push_back(0.0);
        else{
            // a ~ b 까지의 넓이
            double area = Integral(a, b, hail);
            answer.push_back(area);
        }
    }
    
    return answer;
}