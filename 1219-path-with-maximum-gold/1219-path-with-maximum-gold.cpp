// class Solution {
// public:
//     int getMaximumGold(vector<vector<int>>& grid) {
        

//     }
// };



class Solution {
public:

int n,m;

vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};


int dfs(vector<vector<int>> &grid, int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;

    int currGold = grid[i][j];

    grid[i][j] = 0;

    int maxGold = 0;

    for(vector<int> &d: dir){
        int new_r = i + d[0];

        int new_c = j + d[1];

        maxGold = max(maxGold,dfs(grid,new_r,new_c));
    }


    grid[i][j] = currGold;

    return currGold + maxGold;


}

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();


        m = grid[0].size();


        int max_gold = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    max_gold = max(max_gold,dfs(grid,i,j));
                }
            }
        }

        return max_gold;
    }
};