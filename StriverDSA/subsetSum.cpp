#include <iostream>
#include <vector>
using namespace std;

vector<int> glob;

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


int main(){
    vector<int> nums = {2,3};
    vector<int> temp;
    subsetSumsTemp(nums,0,0);
    sort(glob.begin(),glob.end());
    for(auto vec:glob){
        cout << vec;
    }
}