/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/


class Solution {
public:
    unordered_set<char> rowSet;
    unordered_map<int,unordered_set<char>> boxMap;
    unordered_map<int,unordered_set<char>> colMap;
    const string digits = "0123456789";
    
    bool validateRow(vector<char>& row, int row_num){
        char holder;
        rowSet.clear();
        
        //since we are going from bottom-up... when row_num = 8,5,2 - clear the boxMap
        if( (row_num+1)%3==0){
            boxMap.clear();
            cout<<"rownum: "<<row_num<<" clearing boxMap..."<<boxMap.size()<<endl;
        }
        cout<<"processing row "<<row_num<<endl;
        //cout<<"rowSet:"<<rowSet.size()<<endl;
        
        //cout<<"row size: "<<row.size()<<endl;
        for (int i=0; i<row.size();i++){
            holder = row.at(i);
            //skip the "."

            if(holder!='.'){
                //cout<<"holder: "<<holder<<endl;
                
                //character is other than 0-9
                if(!digits.find(holder))
                    return false;
                
                //validate row
                if(rowSet.find(holder)==rowSet.end()){
                    rowSet.insert(holder);
                    //continue;
                    //cout<<"rowSet: "<<rowSet.size()<<endl;
                } else {
                    cout<<"holder: "<<holder<<" failed row validation"<<endl;
                    return false;
                }
                
                //validate column
                if(colMap[i].find(holder)==colMap[i].end()){
                    colMap[i].insert(holder);
                    //continue;
                    //cout<<"colMap["<<i<<"]:"<<colMap[i].size()<<endl;
                } else {
                    cout<<"holder: "<<holder<<" failed column validation"<<endl;
                    return false;
                }
                
                //validate box
                if(boxMap[(int)(i/3)].find(holder)==boxMap[(int)(i/3)].end()){
                    boxMap[(int)(i/3)].insert(holder);
                    cout<<"boxMap["<<(int)(i/3)<<"]:"<<boxMap[(int)(i/3)].size()<<endl;
                } else {
                    cout<<"holder: "<<holder<<" failed box validation"<<endl;
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size()-1;
        bool flag = validateRow(board[row],row);
        //cout<<"processing row "<<row<<"; flag: "<<flag<<endl;
        while(flag && row>0){
            flag = validateRow(board[--row],row);
        }
        
        rowSet.clear();
        colMap.clear();
        return flag;
    }
};



/*

// Cleaner solution
// using 2D arrays for row, col and box validation
//initialize the 2D array to null and assign the numeric value of char to the cell
//if value exists - invald

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int frow[9][9]={0}, fcol[9][9]={0}, fbox[3][3][9]={0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    if (frow[i][val] || fcol[j][val] || fbox[i/3][j/3][val])
                        return false;
                    frow[i][val] = fcol[j][val] = fbox[i/3][j/3][val] = 1;
                }
            }
        }
        return true;
    }
};

// JAVA Solution - 
public boolean isValidSudoku(char[][] board) {
    Set seen = new HashSet();
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            char number = board[i][j];
            if (number != '.')
                if (!seen.add(number + " in row " + i) ||
                    !seen.add(number + " in column " + j) ||
                    !seen.add(number + " in block " + i/3 + "-" + j/3))
                    return false;
        }
    }
    return true;
}

*/