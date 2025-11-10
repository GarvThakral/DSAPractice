class Solution {
public:
    int divide(int dividend, int divisor) {
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
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;

    long long sum = 0;
    long long dvd = dividend;
    long long dvs = divisor;
    dvd = llabs(dvd);
    dvs = llabs(dvs);
    while(dvd >= dvs){
        int maxPow = 0;
        while(maxPow < 32 && dvd >= (dvs<< maxPow)){
            maxPow++;
        }
        // if((sum+(1LL << (maxPow-1)) > INT_MAX && !isNegative)) return INT_MAX;
        // if((sum+(1LL << (maxPow-1)) > INT_MAX && isNegative))return INT_MIN;
        dvd -= (dvs << maxPow-1);
        sum += (1LL << (maxPow-1));

    }

    if(isNegative){
        return -sum;
    }
    return sum;
    }
};