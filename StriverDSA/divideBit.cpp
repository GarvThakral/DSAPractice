#include <iostream>
#include <cmath>
#include <climits>
using namespace std;


int divideBit(int dividend , int divisor){
    if(dividend ==0 || divisor == 0){
        return 0;
    }
    bool isNegative = false;
    if((dividend < 0 || divisor < 0 )){
        if(dividend < 0 && divisor < 0){
            
        }else{
            isNegative = true;
        }
    }
    int sum = 0;
    dividend = abs(dividend);
    divisor = abs(divisor);
    while(dividend >= divisor){
        int maxPow = 0;
        while(dividend >= (divisor<< maxPow) ){
            maxPow++;
        }
        dividend -= (divisor << maxPow-1);
        sum+=pow(2,maxPow-1);
    }
    if(sum == INT_MIN){
        return INT_MAX-1;
    }
    if(isNegative){
        return -sum;
    }
    return sum;
}

int main(){
    cout << divideBit(10,0);
}