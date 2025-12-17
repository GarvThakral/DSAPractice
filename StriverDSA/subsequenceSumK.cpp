#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> glob;

void checkSubsequenceSum(vector<int>& nums,int index, int target ,vector<int> temp) {
    if(target == 0){
        glob.push_back(temp);
        return;
    }
    if(index == (nums.size()) || target < 0){
        return;
    }
    temp.push_back(nums[index]);
    checkSubsequenceSum(nums,index+1,target-nums[index],temp);
    temp.pop_back();
    checkSubsequenceSum(nums,index+1,target,temp);
}




int main(){
    vector<int> nums = {1,2,3,4,5};
    vector<int> temp;
    checkSubsequenceSum(nums,0,8 ,temp);
    cout 
}