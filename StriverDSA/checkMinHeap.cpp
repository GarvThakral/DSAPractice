#include <iostream>
#include <vector>
using namespace std;


bool isMinHeap(vector<int>& arr,int size , int index){
    if(index > size){
        return true;
    }
    int leftChild = index*2;
    int rightChild = index*2+1;
    int smaller = index;
    if(leftChild <= size && arr[index] > arr[leftChild]){
        smaller = leftChild;
    }
    if(rightChild <= size && arr[smaller] > arr[rightChild]){
        smaller = rightChild;
    }
    if(smaller != index){
        return false;
    }
    return isMinHeap(arr,size,leftChild) && isMinHeap(arr,size,rightChild);
}

void minHeapToMaxHeap(vector<int>& arr,int size,int index){
    int leftChild = index*2;
    int rightChild = index*2+1;
    int bigger = index;
    if(leftChild <= size && arr[index] < arr[leftChild]){
        bigger = leftChild;
    }
    if(rightChild <= size && arr[bigger] < arr[rightChild]){
        bigger = rightChild;
    }
    if(bigger != index){
        swap(arr[bigger],arr[index]);
        minHeapToMaxHeap(arr,size,bigger);
    }
}

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7};
    int size = 7;   // false (5 > 3)
    int n = 7;   // false (5 > 3)
    for(int i = n/2 ; n >= 1 ; n--){
        minHeapToMaxHeap(arr,size,1);
    }
    for(int x:arr){
        cout << x << " ";
    }cout << endl;
}