#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;



bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row =  0;
    int col = matrix[0].size()-1;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] > target){
            col--;
        }else{
            row++;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // int m = 2;
    cout << searchMatrix(matrix,5);
}


