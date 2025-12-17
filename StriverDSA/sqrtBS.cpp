#include <iostream>
using namespace std;

int findSqt(int num){
    int low = 0;
    int high = num;
    int ans = 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid*mid == num){
            ans = mid;
            return ans;
        }else if(mid*mid > num){
            high = mid-1;
        }else{
            low = mid+1;
            ans = mid;
        }
    }
    return ans;
}

int main(){
    int ans = findSqt(50);
    cout << ans;
}