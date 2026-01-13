#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minJumpsGLob = INT_MAX;

int minJumps(vector<int> nums){
    int leftRange = 0;
    int rightRange = 0;
    int tempRight = 0;
    int numJumps = 0;
    for(int i = 0 ; i < nums.size() ;i++){
        if(rightRange>=nums.size()-1) return numJumps;
        numJumps++;
        for(int j = leftRange ; j <= rightRange ; j++){
            tempRight = max(tempRight,nums[j]);
        }
        leftRange=rightRange+1;
        rightRange+=tempRight;
    }
    return numJumps;
}

int main(){
    vector<int> nums = {2,3,0,1,4};
    int ans = minJumps(nums);
    cout << ans;
}

class Solution {
public:
int minJumpsGLob = INT_MAX;

int minJumps(vector<int> nums){
    int leftRange = 0;
    int rightRange = 0;
    int tempRight = 0;
    int numJumps = 0;
    for(int i = 0 ; i < nums.size() ;i++){
        int tempRight = rightRange;  
        if(rightRange>=nums.size()-1) return numJumps;
        numJumps++;
        for(int j = leftRange ; j <= rightRange ; j++){
            tempRight = max(tempRight,j+nums[j]);
        }
        leftRange=rightRange+1;
        rightRange=tempRight;
    }
    return numJumps;
}
int jump(vector<int>& nums) {
    return minJumps(nums);
}
};