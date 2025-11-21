#include <iostream>
using namespace std;

int xorRange(int start , int end){
    int xored = 0;
    for(int i = start ; i <= end ; i++){
        xored ^= i;
    }
    return xored;
}

int zeroToNumXor(int num){
    if(num%4 == 0){
        return num;
    }else if(num%4 == 1){
        return 1;
    }else if(num%4 == 2){
        return num+1;
    }else{
        return 0;
    }
}

int xorRangeOptimal(int start , int end){
    if(start == 0)return zeroToNumXor(end);
    int endXor = zeroToNumXor(end);
    int startXor = zeroToNumXor(start-1);
    return endXor ^ startXor;
}


int main(){
    cout << xorRangeOptimal(4,10);
}