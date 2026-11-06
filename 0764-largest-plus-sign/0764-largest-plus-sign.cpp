class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> grid(n,vector<int> (n,1));

        for(auto &ele : mines){
            int i = ele[0];
            int j = ele[1];

            grid[i][j] = 0;
        }

        // building left to right sum

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) sum = 0;
                else sum += grid[i][j];
                grid[i][j] = sum;
            }
        }

        // building right to left sum

        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 0) count = 0;
                else count++;
                grid[i][j] = min(grid[i][j],count);
            }
        }


        // bulding top to down 

        for(int j = 0; j < n; j++){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][j] == 0) count = 0;
                else count++;
                grid[i][j] = min(grid[i][j],count);
            }
        }


        int ans = 0;

        // now building down to top

        for(int j = 0; j < n; j++){
            int count = 0;
            for(int i = n-1; i >= 0; i--){
                if(grid[i][j] == 0) count = 0;
                else count++;
                grid[i][j] = min(grid[i][j],count);
                ans = max(ans,grid[i][j]);
            }
        }

        return ans;


    }
};