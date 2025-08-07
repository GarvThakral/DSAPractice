#include <iostream>
#include <cmath>
using namespace std;

int findNth(int n,int target){
    int low = 0 ; 
    int high = target;
    while(low <= high){
        int mid = (low+high)/2;
        if(pow(mid,n) == target){
            return mid;
        }else if(pow(mid,n) > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int ans = findNth(4,69);
    cout << ans;
}