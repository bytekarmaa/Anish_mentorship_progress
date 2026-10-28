class Solution {
public:

vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
int rows;
int cols;

vector<vector<int>> ref;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        ref = heights;

        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;

        for(int i = 0; i < rows; i++){
            pacific.push({i,0});
            atlantic.push({i,cols-1});
        }
        for(int i = 1; i < cols; i++) pacific.push({0,i});
        for(int i = 0; i < cols-1; i++) atlantic.push({rows-1,i});

        vector<vector<bool>> paci  = bfs(pacific);
        vector<vector<bool>> atlan = bfs(atlantic);

        vector<vector<int>> res;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(paci[i][j] && atlan[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }


    vector<vector<bool>> bfs(queue<pair<int,int>>& q){
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        while(q.size() > 0){
            auto ele = q.front();
            q.pop();
            int i = ele.first;
            int j = ele.second;
            visited[i][j] = true;
            for(int d = 0; d < 4; d++){
                int r = i + dir[d][0];
                int c = j + dir[d][1];

                if(r < 0 || r >= rows || c < 0 || c >= cols) continue;
                if(ref[i][j] > ref[r][c] || visited[r][c]) continue;
                q.push({r,c});
            }
        }
        return visited;
    }

};