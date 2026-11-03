class Solution {
public:
    vector<int> state;   // 0 = unvisited, 1 = visiting, 2 = visited
    
    bool dfs(int node, vector<vector<int>> &adj) {
        state[node] = 1;  // mark as visiting

        for (int nei : adj[node]) {
            if (state[nei] == 1) return false;        // cycle detected
            if (state[nei] == 0 && !dfs(nei, adj))    // recurse
                return false;
        }

        state[node] = 2;  // mark as visited
        return true;
    }

    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        state.assign(v, 0);

        for (int i = 0; i < v; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj)) return false; // cycle found
            }
        }

        return true; // no cycle found
    }
};
