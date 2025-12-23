class Solution {
public:
vector<int> nse(vector<int> nums){
    stack<int> s1;
    vector<int> answer;
    for(int i = nums.size()-1;i >= 0 ;i--){
        if(s1.empty()){
            answer.push_back(nums.size());
            s1.push(i);
        }else if(nums[s1.top()] > nums[i]){
            while(!s1.empty() && nums[s1.top()] > nums[i]){
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
vector<int> pse(vector<int> nums){
    stack<int> s1;
    vector<int> answer;
    for(int i = 0;i < nums.size() ;i++){
        if(s1.empty()){
            answer.push_back(-1);
            s1.push(i);
        }else if(nums[s1.top()] >= nums[i]){
            while(!s1.empty() && nums[s1.top()] >= nums[i]){
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

    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        vector<int> prev = pse(arr);
        vector<int> next = nse(arr);
        long long total = 0;

        for(int i = 0; i < arr.size(); i++){
            long long mul =
                1LL * (i - prev[i]) * (next[i] - i) % MOD * arr[i] % MOD;
            total = (total + mul) % MOD;
        }
        return total;
    }

};