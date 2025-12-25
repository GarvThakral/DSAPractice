#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nse(vector<int>& nums){
    stack<int> s1;
    vector<int> answer;
    for(int i = nums.size()-1 ; i >= 0 ;i--){
        if(s1.empty()){
            answer.push_back(nums.size());
            s1.push(i);
        }else if(nums[s1.top()] >= nums[i]){
            while(!s1.empty() && nums[s1.top()] >= nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                answer.push_back(nums.size());
                s1.push(i);
            }else{
                answer.push_back(s1.top());
                s1.push(i);
            }
        }else{
            answer.push_back(s1.top());
            s1.push(i);
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
vector<int> pse(vector<int>& nums){
    stack<int> s1;
    vector<int> answer;
    for(int i = 0 ; i < nums.size() ; i++){
        if(s1.empty()){
            answer.push_back(-1);
            s1.push(i);
        }else if(nums[s1.top()] > nums[i]){
            while(!s1.empty() && nums[s1.top()] > nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                answer.push_back(-1);
                s1.push(i);
            }else{
                answer.push_back(s1.top());
                s1.push(i);
            }
        }else{
            answer.push_back(s1.top());
            s1.push(i);
        }
    }
    return answer;
}
vector<int> nge(vector<int>& nums){
    stack<int> s1;
    vector<int> answer;
    for(int i = nums.size()-1 ; i >= 0 ;i--){
        if(s1.empty()){
            answer.push_back(nums.size());
            s1.push(i);
        }else if(nums[s1.top()] <= nums[i]){
            while(!s1.empty() && nums[s1.top()] <= nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                answer.push_back(nums.size());
                s1.push(i);
            }else{
                answer.push_back(s1.top());
                s1.push(i);
            }
        }else{
            answer.push_back(s1.top());
            s1.push(i);
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
vector<int> pge(vector<int>& nums){
    stack<int> s1;
    vector<int> answer;
    for(int i = 0 ; i < nums.size() ; i++){
        if(s1.empty()){
            answer.push_back(-1);
            s1.push(i);
        }else if(nums[s1.top()] < nums[i]){
            while(!s1.empty() && nums[s1.top()] < nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                answer.push_back(-1);
                s1.push(i);
            }else{
                answer.push_back(s1.top());
                s1.push(i);
            }
        }else{
            answer.push_back(s1.top());
            s1.push(i);
        }
    }
    return answer;
}

int subarray_min(vector<int>& nums){
    vector<int> nse_an = nse(nums);
    vector<int> pse_an = pse(nums);
    vector<int> nge_an = nge(nums);
    vector<int> pge_an = pge(nums);
    int total = 0;
    int total_an = 0;
    for(int i = 0 ; i < nums.size() ;i++){
        int lower_an = nse_an[i]-i;
        int upper_an = i-pse_an[i];
        int mul_an = lower_an*upper_an*nums[i];
        total += mul_an;
        int lower = nge_an[i]-i;
        int upper = i-pge_an[i];
        int mul = lower*upper*nums[i];
        total_an += mul;
    }
    return total_an - total;
}

int main(){
    vector<int> nums = {1,4,6,7,3,7,8,1};
    cout << subarray_min(nums);
}