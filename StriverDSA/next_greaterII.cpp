#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nextG(vector<int> nums){
    stack<int> glob ;
    for(int i = nums.size() - 1; i >= 0 ; i--){
        if(glob.empty()){
            glob.push(nums[i]);
        }else if(glob.top() > nums[i]){
            glob.push(nums[i]);
        }else{
            while(!glob.empty() && glob.top() <= nums[i]){
                glob.pop();
            }
            glob.push(nums[i]);
        }
    }
    vector<int> ans;
    for(int i = nums.size() - 1; i >= 0 ; i--){
        if(glob.empty()){
            ans.push_back(-1);
            glob.push(nums[i]);
        }else if(glob.top() > nums[i]){
            ans.push_back(glob.top());
            glob.push(nums[i]);
        }else{
            while(!glob.empty() && glob.top() <= nums[i]){
                glob.pop();
            }
            if(glob.empty()){
                ans.push_back(-1);
                glob.push(nums[i]);
            }else{
                ans.push_back(glob.top());
                glob.push(nums[i]);
            }
        }
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    vector<int> nums= {2,10,12,1,11};
    vector<int> ans = nextG(nums);
    for(int x:ans){
        cout << x << " ";
    }
}