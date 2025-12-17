#include <iostream>
using namespace std;

bool checkIthBit(int n, int i) {
    if(i == 0 || i>=32) return false;
    n = n >> i;
    return n&1 == 1;
}

void swap_numbers(int& a , int& b){
    a = a^b;
    b = a^b;
    a = a^b;
}

bool isEven(int num){
    return (num&1) == 0;
}

int setIthBit(int num,int i){
    return num | (1 << i);
}

int main(){
    // cout << checkIthBit(16, 3);
    int x = 5;
    int y = 7;
    swap_numbers(x,y);
    cout << y;
}