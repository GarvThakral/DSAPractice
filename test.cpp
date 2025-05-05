#include <iostream>
#include <vector>
using namespace std;

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void checkPalin(vector<int> &arr) {
    int* ptr = &arr[0];
    int* ptr1 = &arr[arr.size()-1];
    swap(ptr , ptr1);
    string newString;
    
    return;
}

int main(){
    // vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);
    // reverseArray(arr);
    // cout << arr[0];
    string checl  = "    asd as    ";
    cout << checl;
    cout << "hi";

}