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

// Python implementation
// def kthElement(a, b, k):
//     numEl = 0
//     i = 0
//     j = 0
//     n = len(a)
//     n1 = len(b)
//     val = 0
//     while(i < n and j < n1):
//         if(numEl == k):
//             return val
//         if(a[i] < b[j]):
//             numEl+=1
//             val = a[i]
//             i+=1
//         else:
//             numEl+=1
//             val = a[j]
//             j+=1
//     while(j < n1):
//         if(numEl == k):
//             return b[j]
//         numEl+=1
//         j+=1
//     while(i < n1):
//         if(numEl == k):
//             return a[i]
//         numEl+=1
//         i+=1
//     return val