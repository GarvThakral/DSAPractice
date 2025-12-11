#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


vector<int> find_next_greater(vector<int> nums){
    stack<int> glob;
    vector<int> ans;
    for(int i = nums.size()-1 ;i >= 0 ;i--){
        if(glob.empty()){
            glob.push(nums[i]);
            ans.push_back(-1);
        }else if(glob.top() > nums[i]){
            ans.push_back(glob.top());
            glob.push(nums[i]);
        }else{
            while(!glob.empty() && glob.top()<=nums[i]){
                glob.pop();
            }
            if(!glob.empty()){
                ans.push_back(glob.top());
                glob.push(nums[i]);
            }else{
                glob.push(nums[i]);
                ans.push_back(-1);
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> nums = {5,3,4};
    vector<int> ans = find_next_greater(nums);
    for(int x:ans){
        cout << x << " ";
    }
}