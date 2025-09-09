#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int findSmEq(vector<vector<int>> matrix , int x){
    int total = 0;
    for(int i = 0 ; i < matrix.size() ;i++){
        if(matrix[i][0] > x) break;
        int low = 0;
        int high = matrix[i].size()-1;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(matrix[i][mid] <= x){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }
        total+=ans;
    }
    return total;
}

int findMedian(vector<vector<int>>&matrix) {
    int low = INT_MAX;
    int high = 0;
    int ans = 0;
    int median_index = (matrix.size()*matrix[0].size())/2;
    int n = matrix[0].size()-1;
    for(int i = 0 ; i < matrix.size() ;i++){
        low = min(low , matrix[i][0]);
        high = max(high , matrix[i][n]);
    }    
    while(low <= high){
        int mid = (low+high)/2;
        int smallerEquals = findSmEq(matrix,mid);
        if(smallerEquals<=median_index){
            low = mid+1;
        }else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix= { 
        {1, 4, 9},
        {2, 5, 6},
        {3, 7, 8} 
    }; 
    cout << findMedian(matrix);
}