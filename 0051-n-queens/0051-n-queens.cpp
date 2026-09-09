// class Solution {
// public:

// vector<vector<string>> res;

// vector<vector<char>> grid;


// bool canPlace(int row, int col,int n){
//     // first checking in column 

//     for(int i = row-1; i >= 0; i--){
//         if(grid[i][col] == 'Q') return false;
//     }

//     // checking in left diagonal

//     for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--,j--){
//         if(grid[i][j] == 'Q') return false;
//     }

//     // checcking in right diagonal

//     for(int i = row-1, j = col+1; i >= 0 and  j < n; i--,j++){
//         if(grid[i][j] == 'Q') return false;
//     }


//     return true;
// }


// void solve(int row, int n){
//     if(row == n){
//         vector<string> tem;
//         for (vector<char> &ele : grid){
//             tem.push_back(string(ele.begin(), ele.end()));
//         }

//         res.push_back(tem);

//         return;
//     }

//     for(int col = 0; col < n; col++){  // placing the only queen in row
//         if(canPlace(row,col,n)){
//             grid[row][col] = 'Q';
//             solve(row+1,n);
//             grid[row][col] = '.';
//         }
//     }

//     return;
// }

//     vector<vector<string>> solveNQueens(int n) {
//         grid.resize(n,vector<char> (n,'.'));
//         res.clear();


//         solve(0,n);

//         return res;
//     }
// };



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        
        // Initial parameters
        solve(0, n, 0, 0, 0, board, res);
        
        return res;
    }
    
private:
    void solve(int row, int n, int colMask, int mainDiagMask, int antiDiagMask,  vector<string>& board, vector<vector<string>>& res) {
        
        // Base Case: Saari rows fill ho gayi
        if (row == n) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            
            // 1. Teri approach wale exact IDs
            int mainDiagId = row - col + (n - 1);  // Origin shifting
            int antiDiagId = row + col;
            
            // 2. Un IDs ke corresponding Bits nikal lo
            int colBit      = (1 << col);
            int mainDiagBit = (1 << mainDiagId);
            int antiDiagBit = (1 << antiDiagId);
            
            // 3. Safety Check: Koi bit already set toh nahi hai?
            if ((colMask & colBit) || (mainDiagMask & mainDiagBit) || (antiDiagMask & antiDiagBit)) {
                continue; // Danger hai, agli column check karo
            }
            
            // 4. Place the Queen
            board[row][col] = 'Q';
            
            // 5. Agli recursion ke liye naye masks ready karo (Super clean structure)
            int nextRow          = row + 1;
            int nextColMask      = colMask | colBit;
            int nextMainDiagMask = mainDiagMask | mainDiagBit;
            int nextAntiDiagMask = antiDiagMask | antiDiagBit;
            
            // 6. Recursive Call
            solve(nextRow, n, nextColMask, nextMainDiagMask, nextAntiDiagMask, board, res);
            
            // 7. Backtrack: Queen hatao
            board[row][col] = '.';
        }
    }
};