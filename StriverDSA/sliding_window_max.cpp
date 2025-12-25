#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> answer;
    for(int i = 0 ; i < nums.size() ; i++){
        if(i < k-1){
            if(dq.empty()){
                dq.push_front(i);
            }else{
                if(nums[dq.back()] > nums[i]){
                    dq.push_back(i);
                }else{
                    while(!dq.empty() && nums[dq.back()] <= nums[i]){
                        dq.pop_back();
                    }
                    dq.push_back(i);
                }
            }
        }else{
            if(dq.empty()){
                dq.push_front(i);
            }else{
                if(nums[dq.back()] > nums[i]){
                    dq.push_back(i);
                }else{
                    while(!dq.empty() && nums[dq.back()] <= nums[i]){
                        dq.pop_back();
                    }
                    dq.push_back(i);
                }
            }
            while(!dq.empty() && dq.front() < i-k){
                dq.pop_front();
            }
            answer.push_back(nums[dq.front()]);
        }
    }
    return answer;
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,7,1,6};
    vector<int> ans = maxSlidingWindow(nums,3);
    for(int x:ans){
        cout << x << " ";
    }
}