#include <iostream>
#include <vector>
using namespace std;


int floorEl(vector<int> nums,int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return nums[mid];
        }else if(nums[mid] < target){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return nums[ans];
}
int ceilEl(vector<int> nums,int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid]>=target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return nums[ans];
}


int main(){
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int ans = floorEl(nums , 8);
    int ans1 = ceilEl(nums , 8);
    cout << ans;
    cout << ans1;
}