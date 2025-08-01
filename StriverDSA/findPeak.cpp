class Solution {
public:
    bool isPeak(int l , int m , int r){
        if(m > l && m > r){
            return true;
        }
        return false;
    }
    int findPeakElement(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-2;
        int n = nums.size()-1;
        if(nums.size() == 1){
            return 0;
        }
        if(nums[n] > nums[n-1]){
            return n;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        while(low  <= high){
            int mid = (low+high)/2;
            if(isPeak(nums[mid-1],nums[mid],nums[mid+1])){
                return mid;
            }else if(nums[mid-1] < nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};