#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> prefixMax(vector<int> nums){
    vector<int> answer;
    answer.push_back(nums[0]);
    int maxSoFar = nums[0];
    for(int i = 1 ; i < nums.size() ;i++){
        maxSoFar = max(maxSoFar,nums[i]);
        answer.push_back(maxSoFar);
    }
    return answer;
}
vector<int> suffixMax(vector<int> nums){
    vector<int> answer;
    answer.push_back(nums[nums.size()-1]);
    int maxSoFar = nums[nums.size()-1];
    for(int i = nums.size()-2 ; i >= 0 ;i--){
        maxSoFar = max(maxSoFar,nums[i]);
        answer.push_back(maxSoFar);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int trapping_water(vector<int> nums){
    vector<int> pref = prefixMax(nums);
    vector<int> suff = suffixMax(nums);
    int total =0;
    for(int i = 0 ; i < nums.size() ;i++){
        if(nums[i] < pref[i] && nums[i] < suff[i]){
            total += min(pref[i],suff[i]) - nums[i];
        }
    }
    return total;
}


int main(){
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapping_water(nums);
}