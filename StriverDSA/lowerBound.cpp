#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> nums,int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}   

int upperBound(vector<int> nums,int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] > target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}   

int main(){
    int target = 8;
    vector<int> nums = {2,3,6,7,8,8,11,11,11,12};


    int ans = upperBound(nums,target);
    cout << ans;
}