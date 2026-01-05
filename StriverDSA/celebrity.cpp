#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int celebrity(vector<vector<int>> nums){
    int top = 0;
    int down = nums.size()-1;
    while(top!=down){
        if(nums[top][down] == 1){
            top++;
            continue;
        }else{
            down--;
        }
    }
    int c = top;
    for(int i = 0; i < nums.size(); i++){
        if(i == c) continue;
        if(nums[c][i] == 1 || nums[i][c] == 0) return -1;
    }
    return c;
}

int main(){
    vector<vector<int>> nums = {{0,1,1,0},{0,0,0,0},{0,1,0,0},{1,1,0,0}};
    cout << celebrity(nums);
}