#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int count1s(vector<int> row){
    int num1s = 0;
    int ans = INT_MIN;
    int low = 0;
    int high = row.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(row[mid]>=1){
            ans = mid;
            high = mid-1;
        }else{
            low =mid+1;
        }
    }
    if(ans == INT_MIN){
        return 0;
    }
    return row.size()-ans;
}

int rowWithMax1s(vector < vector < int >> & mat) {
    int maxRow = -1;
    int max1s = 0;
    for(int i = 0 ; i < mat.size() ;i++){
        int ones = count1s(mat[i]);
        if( ones > max1s){
            max1s = ones;
            maxRow = i; 
        }   
    }
    return maxRow;
}

int main(){
    vector<vector<int>> mat = { {1, 1, 1}, {0, 0, 1}, {0, 0, 0} };
    // int m = 2;
    cout << rowWithMax1s(mat);
}


[1,3,5,7],[10,11,16,20],[23,30,34,60]