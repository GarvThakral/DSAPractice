#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int recursiveBinary(vector<int> nums , int low , int high , int tar){
        if(low > high){
            return -1;
        }
        int mid = (low+high)/2;
        if(nums[mid] == tar){
            return mid;
        }
        if(nums[mid] < tar){
            return recursiveBinary(nums , mid+1 , high , tar);
        }
        return recursiveBinary(nums , low , mid-1 , tar);
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int ans = recursiveBinary(nums,low,high,target);
        return ans;
    }
};