#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minJumpsGLob = INT_MAX;

void minJumps(vector<int> nums,int currIndex,int numJumps){
    if(currIndex >= nums.size()-1){
        minJumpsGLob = min(minJumpsGLob,numJumps);
        return;
    }
    if(nums[currIndex]==0){
        return;
    }
    for(int i = 1 ; i <= nums[currIndex] ; i++){
        minJumps(nums,currIndex+i,numJumps+1);
    }   
}

int main(){
    vector<int> nums = {2,3,0,1,4};
    minJumps(nums,0,0);
    cout << minJumpsGLob;
}