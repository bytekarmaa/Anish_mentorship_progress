class Solution {
public:

int n,m;

vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

void bfs(vector<vector<char>> &grid, int r, int c){
    queue<pair<int,int>> q;

    q.push({r,c});
    grid[r][c] = '#';

    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();

        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == '1'){
                grid[new_i][new_j] = '#';
                q.push({new_i,new_j});
            }
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
         int ans = 0;
    
         n = grid.size();
         m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }

        // regain the original grid

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '#') grid[i][j] = '1';
            }
        }

        return ans;
    }
};