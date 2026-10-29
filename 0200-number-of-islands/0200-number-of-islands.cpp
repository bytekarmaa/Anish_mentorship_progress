class Solution {
public:

vector<int> parent;
vector<int> rank;

vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

int find(int i){
    if(parent[i] == i) return i;

    return parent[i] = find(parent[i]);
}

void Union(int i, int j){
    int par_i = find(i);

    int par_j = find(j);

    if(par_i == par_j) return;


    if(rank[par_i] < rank[par_j]){
        parent[par_i] = par_j;
    }

    else if(rank[par_i] > rank[par_j]){
        parent[par_j] = par_i;
    }

    else{
        parent[par_i] = par_j;

        rank[par_j]++;
    }

    return;
}

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        parent.resize(n*m);
        rank.resize(n*m,0);

        for(int i = 0; i < n * m; i++) parent[i] = i;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '0') continue;
                int curr = i * m + j;

                for(auto dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= n || new_i < 0 || new_j >= m || new_j < 0 || grid[new_i][new_j] == '0') continue;

                    int next = new_i * m + new_j;

                    Union(curr,next);
                }
            }
        }

       
       unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    int id = i * m + j;
                    st.insert(find(id));
                }
            }
        }

            return st.size();

    }
};