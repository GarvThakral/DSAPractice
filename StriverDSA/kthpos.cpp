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
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        int missing = arr[mid]-(mid+1);
        if(missing < k){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low+k;

}
int main(){
    vector<int> test = {1,2,3,4};
    cout << findKthPositive(test,2);
}