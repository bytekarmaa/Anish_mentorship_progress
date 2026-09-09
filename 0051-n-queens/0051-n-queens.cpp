class Solution {
public:

vector<vector<string>> res;

vector<vector<char>> grid;


bool canPlace(int row, int col,int n){
    // first checking in column 

    for(int i = row-1; i >= 0; i--){
        if(grid[i][col] == 'Q') return false;
    }

    // checking in left diagonal

    for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--,j--){
        if(grid[i][j] == 'Q') return false;
    }

    // checcking in right diagonal

    for(int i = row-1, j = col+1; i >= 0 and  j < n; i--,j++){
        if(grid[i][j] == 'Q') return false;
    }


    return true;
}


void solve(int row, int n){
    if(row == n){
        vector<string> tem;
        for (vector<char> &ele : grid){
            tem.push_back(string(ele.begin(), ele.end()));
        }

        res.push_back(tem);

        return;
    }

    for(int col = 0; col < n; col++){  // placing the only queen in row
        if(canPlace(row,col,n)){
            grid[row][col] = 'Q';
            solve(row+1,n);
            grid[row][col] = '.';
        }
    }

    return;
}

    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n,vector<char> (n,'.'));
        res.clear();


        solve(0,n);

        return res;
    }
};