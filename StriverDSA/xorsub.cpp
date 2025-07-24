#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Brute
// int subarraysWithXorK(vector<int> &nums, int k) {
//     int count = 0;
//     int maxS = 0;
//     for(int i = 0 ; i<nums.size() ;i++){
//         int xorres = 0;
//         for(int j = i;j<nums.size();j++){
//             xorres ^= nums[j]; 
//             if(xorres == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

int subarraysWithXorK(vector<int> &nums, int k) {
    unordered_map<int,int> hashMap;
    int preXor = 0;
    int numSub = 0;
    for(int i =0; i < nums.size();i++){
        if(hashMap.find(preXor)!=hashMap.end()){
            hashMap[preXor]++;
        }else{
            hashMap[preXor]=1;
        }
        preXor = preXor^nums[i];
        int x = preXor^k;
        if(hashMap.find(x)!=hashMap.end()){
            numSub += hashMap[x];
        }
    }
    return numSub;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    int res = subarraysWithXorK(nums,k);
    cout << res;
}