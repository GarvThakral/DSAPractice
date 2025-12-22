#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> find_nse(vector<int>& nums){
    stack<int> s1;
    vector<int> answer;
    int n = nums.size();
    for(int i = n-1;i>=0;i--){
        if(s1.empty()){
            s1.push(i);
            answer.push_back(n);
        }else if(nums[s1.top()] < nums[i]){
            answer.push_back(s1.top());
            s1.push(i);
        }else{
            while(!s1.empty() && nums[s1.top()] >= nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                answer.push_back(n);
            }else{
                answer.push_back(s1.top());
            }
            s1.push(i);
        }
    }   
    reverse(answer.begin(),answer.end());
    return answer;
}

vector<int> find_pse(vector<int>& nums){
    stack<int> s1;
    vector<int> answer;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        if(s1.empty()){
            s1.push(i);
            answer.push_back(-1);
        }else if(nums[s1.top()] < nums[i]){
            answer.push_back(s1.top());
            s1.push(i);
        }else{
            while(!s1.empty() && nums[s1.top()] >= nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                answer.push_back(-1);
            }else{
                answer.push_back(s1.top());
            }
            s1.push(i);
        }
    }   
    return answer;
}

vector<vector<int>> prefixSum(vector<vector<int>>& nums){
    for(int j = 0 ; j < nums[0].size() ;j++){
        int prefixSum = 0;
        for(int i = 0 ; i < nums.size() ;i++){
            if(nums[i][j] == 1){
                nums[i][j] += prefixSum;
                prefixSum+=1;
            }else{
                prefixSum = 0;
            }
        }
    }
    return nums;
}

int main(){
    vector<vector<int>> nums = {
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0},
    };
    nums = prefixSum(nums);
    for(auto x:nums){
        for( auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
    int maxArea = 0;
    for(auto x:nums){
        vector<int> nse = find_nse(x);
        vector<int> pse = find_pse(x);
        for(int i = 0 ; i < nse.size() ;i++){
            maxArea = max(maxArea,x[i] * (nse[i]-pse[i]-1));
        }
    }
    cout << maxArea; 
    return 0;
}