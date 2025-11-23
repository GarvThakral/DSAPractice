class Solution {
public:

    double myPow(double x, int n) {
    double ans =1;
    bool isNeg = false;
    if(x == 1){
        return 1;
    }
    if(x == -1){
        if(n > 0){
            return -1;
        }else{
            return 1;
        }
    }
    if(n == INT_MIN){
        n = -INT_MAX;
    }
    if(n<0){
        isNeg = true;
        n *= -1;
    }
    while(n!=0){
        if((n%2) == 1){
            ans*=x;
            n-=1;
        }else if((n%2) == 0){
            x *= x;
            n /= 2;
        }
    }
    if(isNeg){
        return 1/ans;
    }
    return ans;
    }
};