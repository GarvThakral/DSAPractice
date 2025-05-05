#include <iostream>
using namespace std;


int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }      
        if(i<j){
            swap(arr[i],arr[j]);
        }  
    }    
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low , int high){
    if(low < high){
        int partitionIndex = partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
    }
}

void merge(int arr[],int low , int mid , int high){
    int left = low;
    int right = mid+1;
    int temp[high-low+1];
    int i = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[i] = arr[left];
            left++;
            i++;
        }else{
            temp[i] = arr[right];
            right++;
            i++;
        }
    }
    while(left <= mid){
        temp[i] = arr[left];
        left++;
        i++;
    }
    while(right <= high){
        temp[i] = arr[right];
        right++;
        i++;
    }
    i = 0;
    for(int j = low; j<=high ;j++){
        arr[j] = temp[i];
        i++;
    }
}
void mergeSort(int arr[],int low , int high){
    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}


void swap(int& a , int& b){
    int temp = a;
    a = b;
    b = temp;
    return;
}
// {1,5,2,8,7}
int* insertionSort(int* arr , int size){
    for(int i = 0 ; i <size-1;i++){
        int j = i+1;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    return arr;
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
    int arr[size] = {1,5,3,2,7};
    quickSort(arr,0,4);
    for(int i = 0 ; i < size;i++){
        cout << arr[i] << endl;
    }
}