#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int> nums){
    int xored = 0;
    for(int i = 0 ; i < nums.size() ;i++){
        xored ^= nums[i];
    }
    xored = (xored&(xored-1))^xored;
    int bucket1 =  0;
    int bucket2 =  0;
    
    for(int i = 0 ; i < nums.size() ;i++){
        if((nums[i]&xored) == xored){
            bucket1 ^= nums[i];
        }else{
            bucket2 ^= nums[i];
        }
    }
    return {bucket1,bucket2};
}

int main(){
    vector<int> nums = {2,4,2,14,3,3};
    vector<int> ans = singleNumber(nums);
    for(auto num:ans){
        cout << num << " ";
    }
}