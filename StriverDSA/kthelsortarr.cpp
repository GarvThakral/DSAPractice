#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int k) {
    int numEl = 0;
    int i = 0;
    int j = 0;
    int n = a.size();
    int n1 = b.size();
    int val;
    while(i < n && j <n1){
        if(numEl == k){
            return val;
        }
        if(a[i] > b[j]){
            val = b[j];
            j++;
            numEl++;
        }else{
            val = a[i];

            i++;
            numEl++;
        }
    }
    while(i < n){
        if(numEl == k){
          return a[i];
        }
        i++;
        numEl++;
    }
    while(j <n1){
        if(numEl == k){
          return b[j];
        }
        
        j++;
        numEl++;
    }
    return 0;
}

int main(){
    vector<int> nums = {100, 112, 256, 349, 770};
    vector<int> nums1 = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;
    cout << kthElement(nums , nums1 , k);
}