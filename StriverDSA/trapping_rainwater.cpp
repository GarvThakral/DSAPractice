#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trapping_water(vector<int> nums){
    stack<int> s1;
    for(int i:nums){
        if(s1.empty()){
            s1.push(i);
        }else if(s1.top() >= i){
            s1.push(i);
        }else{
            int leftMax = 0;
            int leftmid = 0;
            while(!s1.empty() && s1.top() < i){

            }
        }
    }
}


int main(){
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapping_water(nums);
}