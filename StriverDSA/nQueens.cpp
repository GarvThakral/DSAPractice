class Solution {
public:
    bool isSafe(int n, int r , int c,vector<vector<string>> board){
        int i = 0;
        while(i >= 0 && i<= n){
            if(temp[r-i][c-i] == 'Q'){
                return false;
            }
            i--;
        }
        i = 0;
        while(i >= 0 && i<= n){
            if(temp[r+i][c+i] == 'Q'){
                return false;
            }
            i--;
        }
        i = 0;
        while((i >= 0 && i<= n) && (j >= 0 && j<= n)){
            if(temp[r-i][c-i] == 'Q'){
                return false;
            }
            i--;
        }
        i = 0;
        while(i >= 0 && i<= n){
            if(temp[r-i][c+i] == 'Q'){
                return false;
            }
            i++;
        }

        for(int i = 0 ; i < n; i++){
            if(board[i][c] == 'Q'){
                return false;
            }
            if(board[r][i] == 'Q'){
                return false;
            }
        }
        
    }
    void nQueensTemp(int n , int rowIndex , vector<string> temp){
        for(int column = 0 ; column < n ;column++){
            if(isSafe(rowIndex,column)){
                temp[rowIndex][column] = 'Q';
                nQueensTemp(n,rowIndex+1,temp);
                temp[rowIndex][column] = '.';          
            }
        }
    }   

    vector<vector<string>> solveNQueens(int n) {
        
    }
};