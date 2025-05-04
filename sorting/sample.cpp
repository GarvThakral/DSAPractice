#include <iostream>
using namespace std;

void swap(int& a , int& b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

int* selectionSort(int* arr,int size){
    for(int i = 0 ; i < size ;i++){
        int min = arr[i];
        int minIndex = i;
        for(int j = i ; j < size ; j++){
            if(arr[j]<min){
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
    return arr;
}

int* bubbleSort(int* arr,int size){
    for(int i = size-1 ; i>=1 ; i--){
        for(int j = 0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}

int main(){
    int size = 5;
    int arr[size] = {1,5,2,8,7};
    int* sortedArray = selectionSort(arr,size); 
    for(int i = 0 ; i < size;i++){
        cout << sortedArray[i] << endl;
    }
}