#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool canPlace(vector<int>arr,long double mid,int k){
    int numStations = 0;
    for(int i = 0;i < arr.size()-1;i++){
        int stations = floor((arr[i+1]-arr[i])/mid);
        numStations+=stations;
    }
    return numStations <= k;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    long double low = 0;
    long double high = arr[arr.size()-1];
    long double ans ;
    while(high - low > 1e-6){
        long double mid = (low+high)/2;
        if(canPlace(arr,mid,k)){
            high = mid;
            ans = mid;
        }else{
            low = mid;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
    int k = 9;
    cout << minimiseMaxDistance(nums , 1);
}