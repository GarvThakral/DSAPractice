#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> glob;
vector<vector<int>> globb;

void subsetSumsTemp(vector<int>& nums,int index ,int sum) {

    if(index == nums.size()){
        glob.push_back(sum);
        return;
    }

    // Dont pick
    subsetSumsTemp(nums,index+1,sum);
    // Pick
    subsetSumsTemp(nums,index+1,sum+nums[index]);
    return;

}
class Solution {
public:
    vector<vector<int>> glob;
    void subsetsTemp(vector<int> nums , int index ,vector<int> temp){
        glob.push_back(temp);
        for(int i = index ;i < nums.size() ;i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            subsetsTemp(nums,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        subsetsTemp(nums,0,temp);
        return glob;
    }
};

int main(){
    vector<int> nums = {1,2,2};
    sort(nums.begin(),nums.end());
    vector<int> temp;
    subsetTemp(nums,0,temp);
    sort(glob.begin(),glob.end());
    for(auto vec:globb){
        for(int num:vec){
            cout << num << " ";
        }
        cout << endl;
    }
}