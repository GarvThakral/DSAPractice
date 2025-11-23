#include <iostream>
#include <vector>
using namespace std;


int sieveOf(int n){
    if(n == 2){
        return 0;
    }
    if(n <= 1){
        return 0;
    }
    vector<int> arr(n+1,1);
    for(int i = 2; i <= n ;i++){
        if(arr[i] == 1){
            for(long long j = (1LL*i*i) ; j <= n ;j+=i){
                arr[j] = 0;
            }
        }
    }
    int sum = 0;
    for(int i = 2;i<n;i++){
        if(arr[i] == 1){
            sum++;
        }
    }
    return sum;
}

int main(){
    sieveOf(31);
}