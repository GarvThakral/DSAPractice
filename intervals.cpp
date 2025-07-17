sort(nums.begin(),nums.end());
        int i = 0;
        vector<vector<int>> newVec;
        while(i < nums.size()-1){
            int j = i+1;
            int k = nums.size()-1;
            while( j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]} ;
                    newVec.push_back(temp);
                    int curr_j = nums[j];
                    int curr_k = nums[k];
                    
                    while (j < k && nums[j] == curr_j) j++;  // skip duplicates for j
                    while (j < k && nums[k] == curr_k) k--;  // skip duplicates for kk--;

                    continue;
                }else if(sum > 0){
                    int curr = nums[k];
                    while(j < k && nums[k] == curr){
                        k--;
                    }
                    continue;
                }else{
                    int curr = nums[j];
                    while(j < k && nums[j] == curr){
                        j++;
                    }
                    continue;
                }
            }
            int curr = nums[i];
            while (i < nums.size() && nums[i] == curr) {
                i++;
            }
        }
        return newVec;
