class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> adj(n,vector<bool> (n,0));

        vector<int> deg(n,0);

        for(auto &ele : roads){
            int u = ele[0];
            int v = ele[1];

            deg[u]++;
            deg[v]++;

            adj[u][v] = 1;
            adj[v][u] = 1;
        }


        int maxRank = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int d1 = deg[i];
                int d2 = deg[j];

                int currRank = d1 + d2;

                if(adj[i][j]) currRank--;

                maxRank = max(maxRank,currRank);
            }
        }
       

        return maxRank;
    }
};