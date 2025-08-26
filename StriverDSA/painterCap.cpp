#include <bits/stdc++.h>
using namespace std;


bool canDo(vector<int> C , int painters , int minMaxTime){
    int currTime = 0;
    int numPainters = 1;
    for(int i=0;i<C.size();i++){
        if(C[i]+currTime <= minMaxTime){
            currTime+=C[i];
        }else{
            numPainters+=1;
            currTime = C[i];
        }
    }
    if(painters >= numPainters){
        return true;
    }
    return false;
}

int paint(int A, int B, vector<int>& C) {
    int low = *max_element(C.begin(), C.end());
    int high = accumulate(C.begin(), C.end(), 0);
    int ans = high;

    while(low <= high){
        int mid = (low+high)/2;
        if(canDo(C,A,mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans*B;
}

int main() {
    vector<int> C = {1,8,11,3};
    int A = 10;

    cout << paint(A,1,C) << endl;

    return 0;
}

