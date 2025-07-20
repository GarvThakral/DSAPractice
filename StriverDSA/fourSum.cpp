#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <set>
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ansVec;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size(); j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int k = j + 1;
            int l = nums.size() - 1;
            while (k < l) {
                long long int sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ansVec.push_back(temp);
                    while (k < l && nums[k + 1] == nums[k]) k++;
                    k++;
                    while (k < l && nums[l - 1] == nums[l]) l--;
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return ansVec;
}


int main(){
    vector<int> nums= {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = fourSum(nums,0);
    for(vector<int> x:ans){
        cout << "Triplet ";
        for(int y:x){
            cout << y << " ";
        }
    }
}