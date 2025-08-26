//  // Python brute
// class Solution:
//     def findKthPositive(self, arr: List[int], k: int) -> int:
//         for i in range(len(arr)):
//             if arr[i] <= k:
//                 k+=1
//             else:
//                 break
//         return k
#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    for(int i = 0 ; i < arr.size() ;i++){
        if(arr[i] <= k){
            k++;
        }else{
            break;
        }
    }      
    return k;
}
int main(){
    vector<int> test = {123,123};
    cout << findKthPositive(test,10);
}