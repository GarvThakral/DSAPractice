#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solving for the ThreeSum problem 
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

vector<vector<int>> threeSum(vector<int> nums){
    int n = nums.size();
    vector<vector<int>> ans;
    int k = 0;
    int i = k+1;
    int j = n-1;
    sort(nums.begin(),nums.end());

    while(k < n-1){
        if (k > 0 && nums[k] == nums[k - 1]) continue;

        int i = k + 1;
        int j = n - 1;
        while(i<j){
            int sum = nums[i]+nums[j]+nums[k]; 
            if(sum == 0){
                ans.push_back({nums[i],nums[j],nums[k]});
                int currI = nums[i];
                int currJ =  nums[j];
                
                while(currI == nums[i]){
                    i++;
                }
                while(currJ == nums[j]){
                    j--;
                }
            }
            else if(sum > 0){
                j--;
            }
            else if(sum < 0){
                i++;
            }
        }

    }
    return ans;
}


int main(){
    vector<int> nums= {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    for(vector<int> x:ans){
        cout << "Triplet ";
        for(int y:x){
            cout << y << " ";
        }
    }
}