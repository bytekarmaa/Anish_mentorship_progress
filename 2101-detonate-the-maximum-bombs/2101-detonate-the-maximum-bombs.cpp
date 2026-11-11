class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                
                if (dx * dx + dy * dy <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            queue<int> q;
            
            q.push(i);
            vis[i] = 1;
            int cnt = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                cnt++;
                
                for (int it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};