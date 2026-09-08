class Solution {
public:

    int n, m;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    int solve(vector<vector<int>>& grid, int i, int j, int k, int l, int count) {

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1)
            return 0;

        if(i == k && j == l) {
            return count == 1;
        }

        int original = grid[i][j];
        grid[i][j] = -1;

        int ans = 0;

        for(auto &dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            ans += solve(grid, ni, nj, k, l, count - 1);
        }

        grid[i][j] = original;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int si, sj, ei, ej;
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] != -1)
                    count++;

                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }

                if(grid[i][j] == 2) {
                    ei = i;
                    ej = j;
                }
            }
        }

        return solve(grid, si, sj, ei, ej, count);
    }
};