#include <iostream>
#include <vector>
using namespace std;
int pairCount = 0;
void merge(int low , int high , vector<int>& nums){
    vector<int> temp;
    int mid = (low+high)/2;
    int i = low;
    int j = mid+1;
    int iter = mid+1;
    while(i<=mid && j<=high){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(nums[j]);
        j++;
    }
    int index = 0;
    for(i = low ; i<=high ;i++){
        nums[i] = temp[index];
        index++;
    }
}
void countPairs(int low , int mid , int high, vector<int>& nums){
    int right = mid+1;
    for(int i = low ; i <= mid ;i++){
        while(right <= high && nums[i] > 2*nums[right])right++;
        pairCount += (right - (mid+1));
    }
}

void mergeSort(int low , int high , vector<int>& nums){
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);
        countPairs(low,mid,high,nums);
        merge(low , high , nums);
    }
}


int main(){
    vector<int> nums = {1,3,2,3,1};
    int low = 0;
    int high = nums.size()-1;
    mergeSort(low  , high , nums);
    cout << pairCount;
}