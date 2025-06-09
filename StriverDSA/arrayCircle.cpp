#include <iostream>
#include <vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> finalVec;
    int top = 0;
    int bottom = matrix.size()-1;
    int left = 0;
    int right = matrix[0].size()-1;
    while(top <= bottom && left <= right){
        for(int i = left ; i <= right ;i++){
            finalVec.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top ; i <= bottom ;i++){
            finalVec.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i = right ; i >= left ;i--){
                finalVec.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left <= right){
            for(int i = bottom ; i >= top ;i--){
                finalVec.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    if(top == bottom){
        for(int i = left ; i <= right ;i++){
            finalVec.push_back(matrix[top][i]);
        }
    }

    return finalVec;
}

int main(){
    vector<vector<int>> testVec = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}; 
    vector<int> final = spiralOrder(testVec);
    for(int x:final){
        cout << x;
    }
}