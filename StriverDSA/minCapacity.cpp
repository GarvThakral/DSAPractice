// Python Implementation

// class Solution(object):
//     def shipWithinDays(self, weights, days):
//         """
//         :type weights: List[int]
//         :type days: int
//         :rtype: int
//         """
//         low = max(weights)
//         high = sum(weights)
//         capacity = 0
//         while(low <= high):
//             mid = (low+high)//2
//             day = 1
//             curSum = 0
//             for i in range(len(weights)):
//                 if((weights[i]+curSum)>mid):
//                     curSum = 0
//                     day+=1
//                 curSum+=weights[i]
//             if(day > days):
//                 low = mid +1
//             else:
//                 capacity = mid
//                 high = mid-1
//         return capacity

#include<iostream>
#include<vector>
using namespace std;
int shipWithinDays(vector<int>& weights, int days) {
    int maxEl = 0;
    int sum = 0;
    for(int x:weights){
        maxEl = max(maxEl,x);
        sum+=x;
    }
    int low = maxEl;
    int high = sum;
    int capacity = 0;
    while(low <= high){
        int mid = (low+high)/2;
        int sum = 0;
        int day = 1;
        for(int i = 0 ; i < weights.size() ;i++){
            if(sum >= mid || (sum+weights[i] > mid)){
                sum = 0;
                day++;
            }
            sum+=weights[i];
        }
        if(day > days){
            low = mid+1;
        }else{
            capacity = mid;
            high = mid-1;
        }
    }
    return capacity;

}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << shipWithinDays(weights,days);
}