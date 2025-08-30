#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMake(vector<int> bloomDay,int m ,int k , int days){
    int numBouquets = 0;
    int conti = 0;
    for(int i = 0 ; i < bloomDay.size() ;i++){
        if(bloomDay[i] <= days){
            conti++;
            if(conti == k){
                numBouquets++;
                conti = 0;
            }
        }else{
            conti = 0;
        }
    }
    return numBouquets>=m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if(m * k > bloomDay.size()) return -1;
    int low = 0;
    int high = *max_element(bloomDay.begin(),bloomDay.end());
    int ans = high;
    while(low <= high){
        int mid = (low+high)/2;
        if(canMake(bloomDay,m,k,mid)){
            high = mid-1;
            ans = min(ans,mid);
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1; 
    cout << minDays(bloomDay,m,k);  
}