class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Aapka original visited array
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        deque<p> dq;
        dq.push_front({0, {0,0}}); // Starting point push kar diya

        while(!dq.empty()){
            auto ele = dq.front();
            dq.pop_front();

            int wt = ele.first;
            int i = ele.second.first;
            int j = ele.second.second;

            // Agar pehle process ho chuka hai (yani isse kam cost me visit ho chuka hai), to skip karo
            if(visited[i][j]) continue;
            
            // Pop hone ke baad visit mark karna zaroori hai
            visited[i][j] = true;

            if(i == n-1 && j == m-1) return wt;

            for(auto &dir : directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                int can_i = i;
                int can_j = j;

                int val = grid[i][j];
                
                if(val == 1) can_j++;
                else if(val == 2) can_j--;
                else if(val == 3) can_i++;
                else can_i--;

                // Agar out of bounds hai ya pehle se visited hai, to skip
                if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || visited[new_i][new_j]) continue;

                // Deque logic: cost change nahi ho rahi to front, warna back
                if(new_i == can_i && new_j == can_j) {
                    dq.push_front({wt, {new_i, new_j}});
                } else {
                    dq.push_back({wt+1, {new_i, new_j}});
                }
            }
        }

        return -1;
    }
};