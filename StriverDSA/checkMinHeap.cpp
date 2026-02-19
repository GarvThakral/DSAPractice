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

int main(){
vector<int> arr = {0, 5, 3, 4};
int size = 3;   // false (5 > 3)
    cout << isMinHeap(arr,size,1);
}