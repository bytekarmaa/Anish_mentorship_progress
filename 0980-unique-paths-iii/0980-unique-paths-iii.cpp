class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    int solve(vector<vector<int>>& grid, int i, int j, int k, int l, int count) {
        // Out of bounds or hit an obstacle / already visited square
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1)
            return 0;

        // Reached the destination
        if (i == k && j == l) {
            return count == 0; // Corrected: Path is valid only if we've consumed all required steps
        }

        int original = grid[i][j];
        grid[i][j] = -1; // Mark as visited

        int ans = 0;
        for (auto &dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            // Decrement count for the next step
            ans += solve(grid, ni, nj, k, l, count - 1); 
        }

        grid[i][j] = original; // Backtrack

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int si, sj, ei, ej;
        
        // Start at 1 to account for the final step onto the destination square '2'
        int count = 1; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) 
                    count++; // Corrected: Count empty squares, not obstacles

                else if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                }
                else if (grid[i][j] == 2) {
                    ei = i;
                    ej = j;
                }
            }
        }

        return solve(grid, si, sj, ei, ej, count);
    }
};