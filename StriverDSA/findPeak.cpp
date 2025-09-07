#include <iostream>
#include <vector>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int low = 0;
    int high = mat[0].size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        int maxRow = 0;
        int maxEl = 0;
        for(int i = 0 ; i < mat.size() ;i++){
            if(mat[i][mid] > maxEl){
                maxRow = i;
                maxEl = mat[i][mid];
            }
        }
        int left = mid - 1 > 0 ? mat[maxRow][mid-1]:-1;
        int right = mid + 1 < mat[0].size() ? mat[maxRow][mid+1]:-1;
        if(mat[maxRow][mid] > right && mat[maxRow][mid] > left){
            return {maxRow , mid};
        }else if(mat[maxRow][mid+1] > mat[maxRow][mid]){
            low = mid+1;
        }else{
            high = mid - 1;
        }
    }
}

int main(){
    vector<vector<int>> nums = {{1,4},{3,2}};
    vector<int> ans = findPeakGrid(nums);
    for(auto it:ans){
        cout << it;
    }
}