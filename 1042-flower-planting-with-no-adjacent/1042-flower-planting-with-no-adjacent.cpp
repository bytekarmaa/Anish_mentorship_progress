class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for (auto& p : paths) {
            adj[p[0] - 1].push_back(p[1] - 1);
            adj[p[1] - 1].push_back(p[0] - 1);
        }

        vector<int> res(n, 0);
        for (int u = 0; u < n; ++u) {
            bool used[5] = {};
            for (int v : adj[u]) used[res[v]] = true;  
            for (int c = 1; c <= 4; ++c)
                if (!used[c]) { res[u] = c; break; }
        }
        return res;
    }
};