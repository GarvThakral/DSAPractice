#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
void heapify(vector<int>& arr , int size , int index){
    int leftChild = index*2;
    int rightChild = index*2+1;
    int bigger = index;
    if(leftChild <= size && arr[leftChild] > arr[index]){
        bigger = leftChild; 
    }
    if(rightChild <= size && arr[rightChild] > arr[bigger]){
        bigger = rightChild; 
    }

    if(bigger!=index){
        swap(arr[index],arr[bigger]);
        heapify(arr,size,bigger);
    }
    return;
}

void deleteFromHeap(vector<int>& arr , int& size){
    arr[1] = arr[size];
    size--;
    int index = 1;
    heapify(arr,size,index);
}
    int kthLargestElement(vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        int size = nums.size()-1;
        for(int i = size/2 ; i >= 1 ; i--){
            heapify(nums,size,i);
        }
        for(int i = 1 ; i < k ; i++){
            deleteFromHeap(nums,size);
        }
        return nums[1];
    }
};
int main(){
    vector<int> arr = {0 , 1, 2, 3, 4, 5};
    int size = arr.size()-1;
    for(int i = size/2 ; i >= 1 ; i--){
        heapify(arr,size,i);
    }
    int k = 2;
    for(int i = 1 ; i < k ; i++){
        deleteFromHeap(arr,size);
    }
    for(int i = 1 ; i <= size ; i++){
        cout << arr[i] << ' ';
    }cout << endl;
}