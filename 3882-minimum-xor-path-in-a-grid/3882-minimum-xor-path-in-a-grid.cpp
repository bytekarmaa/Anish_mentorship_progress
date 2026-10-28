class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(1024, false)));


        dp[n-1][m-1][grid[n-1][m-1]] = true;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int val = grid[i][j];

               for (int x = 0; x < 1024; x++) {
                    if (j + 1 < m && dp[i][j+1][x]) {
                        dp[i][j][val ^ x] = true;
                    }

                    if (i + 1 < n && dp[i+1][j][x]) {
                        dp[i][j][val ^ x] = true;
                    }
                }
            }
        }

        for(int x = 0; x <= 1023; x++){
            if(dp[0][0][x]) return x;
        }

        return -1;

    }
};