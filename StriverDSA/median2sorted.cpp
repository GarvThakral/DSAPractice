        // int i = 0;
        // int j = 0;
        // vector<int> arr3;
        // while(i <  nums1.size() && j < nums2.size()){
        //     if(nums1[i] >= nums2[j]){
        //         arr3.push_back(nums2[j]);
        //         j++;
        //     }else{
        //         arr3.push_back(nums1[i]);
        //         i++;
        //     }
        // }
        // while(i <  nums1.size()){
        //     arr3.push_back(nums1[i]);
        //     i++;
        // }
        // while(j <  nums2.size()){
        //     arr3.push_back(nums2[j]);
        //     j++;
        // }
        // if((nums1.size() + nums2.size()) % 2 == 1){
        //     return arr3[arr3.size()/2];
        // }
        // return (arr3[arr3.size()/2]+arr3[arr3.size()/2-1])/2.0; 


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int total = n1 + n2;
        
//         int mid1 = (total - 1) / 2;  
//         int mid2 = total / 2;        
//         int i = 0, j = 0, idx = 0;
//         int val1 = 0, val2 = 0;
        
//         while (i < n1 && j < n2) {
//             int curr;
//             if (nums1[i] < nums2[j]) {
//                 curr = nums1[i++];
//             } else {
//                 curr = nums2[j++];
//             }
            
//             if (idx == mid1) val1 = curr;
//             if (idx == mid2) val2 = curr;
//             idx++;
//         }
        
//         while (i < n1) {
//             int curr = nums1[i++];
//             if (idx == mid1) val1 = curr;
//             if (idx == mid2) val2 = curr;
//             idx++;
//         }
        
//         while (j < n2) {
//             int curr = nums2[j++];
//             if (idx == mid1) val1 = curr;
//             if (idx == mid2) val2 = curr;
//             idx++;
//         }
        
//         if (total % 2 == 0) {
//             return (val1 + val2) / 2.0;
//         }
//         return val2;
//     }
// };


// cpp brute


