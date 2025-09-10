
bool unique_row(vector<char> row){
    map<char,int> rowMap;
    for(int i = 0 ; i < row.size() ;i++){
        if(isdigit(row[i])) rowMap[row[i]] +=1;
    }
    for(auto it:rowMap){
        if(it.second > 1){
            return false;
        }
    }
    return true;
}
bool unique_col(vector<vector<char>> matrix,int colNum){
    map<char,int> colMap;
    for(int i = 0 ; i < matrix.size() ;i++){
        if(isdigit(matrix[i][colNum])) colMap[matrix[i][colNum]] +=1;
    }
    for(auto it:colMap){
        if(it.second > 1){
            return false;
        }
    }
    return true;
}
bool unique_box(vector<vector<char>> box){
    int row_start = 0;
    int col_start = 0;
    int row_end = 3;
    int col_end = 3;
    for(int boxes=1;boxes<=9;boxes++){
        map<char,int> boxMap;
        for(int i = row_start ; i < row_end ;i++){
            for(int j = col_start;j<col_end;j++ ){
                if(isdigit(box[i][j])) boxMap[box[i][j]]+=1;
            }
        }
        for(auto it:boxMap){
            if(it.second > 1){
                return false;
            }
        }
        col_start+=3;
        col_end+=3;
        if(boxes!=1 && boxes%3 ==0){
            row_start+=3;
            row_end=row_start+3;
            col_start = 0;
            col_end = 3;
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < board.size() ;i++){
        if(!unique_row(board[i])) return false;
    }
    for(int i = 0; i < board[i].size() ;i++){
        if(!unique_col(board,i)) return false;
    }

    if(!unique_box(board)) return false;
    return true;

}
