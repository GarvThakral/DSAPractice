#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> leaders(vector<int>& nums) {
    int max = INT_MIN;
    vector<int> leaderList;
    for(int i = nums.size()-1;i>=0;i--){
        if(nums[i] > max){
            leaderList.push_back(nums[i]);
            max = nums[i];
        }
    }
    return leaderList;
}

int main(){
    vector<int> sample = {10,22,12,3,0,6};
    vector<int> answer = leaders(sample);
    for(int x:answer){
        cout << x << " ";
    }
}