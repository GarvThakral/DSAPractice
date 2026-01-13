    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for(int i = 0 ; i < nums.size() ;i++){    
            if(maxIndex >= nums.size()-1){
                return true;
            }
            if(nums[i] == 0 && maxIndex <= i){
                return false;
            }
            maxIndex = max(maxIndex,nums[i]+i);
        }
        return true;
    }