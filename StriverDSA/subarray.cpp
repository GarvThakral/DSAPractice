#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int> &nums, int k){
    int max = 0;
    for(int i = 0 ; i < nums.size() ;i++){
        int sum = 0;
        for(int j = i ; j < nums.size() ;j++){
            cout << sum << endl;
            sum+=nums[j];
            if(sum < k){
                continue;
            }else if(sum == k){
                int size = j-i+1;
                if(size > max){
                    max = size;
                }
            }else if(sum > k){
                break;
            }
            
        }
    }
    return max;
}

int main(){
    vector<int> vec= {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    int result = longestSubarray(vec,k);
    cout << result;
}
