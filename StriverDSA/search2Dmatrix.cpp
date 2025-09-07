#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i = 0 ; i < matrix.size() ;i++){
        int low = 0;
        int high = matrix[i].size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[i][mid] == target){
                cout << i << " " << mid << endl;
                return true; 
            }else if(matrix[i][mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    // int m = 2;
    cout << searchMatrix(matrix,100);
}


