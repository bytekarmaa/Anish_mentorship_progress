class Solution {
public:
    vector<bool> currPath;
    vector<bool> visited;
    vector<int> dist;

    int res = -1;

    void dfs(vector<int> &edges, int node, int d) {
        visited[node] = true;
        currPath[node] = true;
        dist[node] = d;   

        int nextNode = edges[node];

        if (nextNode != -1) {
            if (currPath[nextNode]) {
                //  cycle length
                res = max(res, d - dist[nextNode] + 1);
            }
            else if (!visited[nextNode]) {   
                dfs(edges, nextNode, d + 1);
            }
        }

        currPath[node] = false; // backtrack
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        currPath.assign(n, false);
        visited.assign(n, false);
        dist.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(edges, i, 0);
            }
        }

        return res;
    }
};
