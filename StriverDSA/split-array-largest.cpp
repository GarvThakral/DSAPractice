#include <bits/stdc++.h>
using namespace std;
bool minMaxSum(vector<int
    
    > nums , int maxSum , int numSub){
    int currSum = 0;
    int currSub = 1;
    for(int i = 0 ; i < nums.size() ; i++){
        if(currSum+nums[i] <= maxSum){
            currSum+=nums[i];
        }else{
            currSub+=1;
            currSum = nums[i];
        }
    }
    return currSub <= numSub;
}
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0LL);
    int ans = high;
    while(low <= high){
        int mid = (low+high)/2;
        if(minMaxSum(nums , mid , k)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){

}

// import numpy as np
// class Solution:
//     def minMaxSum(self, nums, maxSum, maxSub):
//         currSum = 0
//         currSub = 1
//         for x in nums:
//             if currSum + x <= maxSum:
//                 currSum += x
//             else:
//                 currSub += 1
//                 currSum = x
//         return currSub <= maxSub  

//     def splitArray(self, nums: List[int], k: int) -> int:
//         low = max(nums)
//         high = sum(nums)  
//         ans = high
//         while low <= high:
//             mid = (low + high) // 2
//             if self.minMaxSum(nums, mid, k):
//                 ans = mid
//                 high = mid - 1
//             else:
//                 low = mid + 1
//         return ans
