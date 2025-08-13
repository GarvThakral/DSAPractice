// Python Implementation
// import numpy as np
// import math
// class Solution:
//     def smallestDivisor(self, nums: List[int], threshold: int) -> int:
//         maxEl = 0
//         for i in nums:
//             maxEl = max(i,maxEl)
//         nums = np.array(nums)
//         low = int(0)
//         high = int(maxEl)
//         ans = None
//         while(low <= high):
//             mid = (low+high)//2
//             res = np.sum(np.ceil(nums/mid))
//             if(res > threshold):
//                 low = mid+1
//             else:
//                 ans = mid
//                 high = mid-1

//         return ans

#include <iostream>
#include <vector>
#include<climits>
#include <cmath>

using namespace std;

int sumOfDiv(vector<int> nums,int mid){
    int sum =0;
    for(int i=0;i < nums.size() ;i++){
        sum += ceil((double)nums[i]/mid);
        
    }
    return sum;

}
int smallestDivisor(vector<int>& nums, int threshold) {
    int maxEl = INT_MIN;
    for(int x:nums){
        maxEl = max(maxEl,x);
    } 
    int low = 1;
    int high = maxEl;
    int ans = 0;
    while(low <= high){
        int mid = (low+high)/2;
        int sum = sumOfDiv(nums,mid);
        if(sum > threshold){
            low = mid+1;
        }else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,5,9};
    int ans = smallestDivisor(nums , 6);
    cout << ans;
}