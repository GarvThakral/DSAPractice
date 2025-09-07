#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int count1s(vector<int> row){
    int num1s = 0;
    for(int x:row){
        if(x == 1) num1s++;
    }
    return num1s;
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


