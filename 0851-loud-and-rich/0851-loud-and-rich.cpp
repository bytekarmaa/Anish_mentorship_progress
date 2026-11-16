class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        
        vector<int> res(n);
        vector<int> adj[n];
        vector<int> indeg(n, 0);

        for(auto &ele : richer){
            int u = ele[0];
            int v = ele[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            res[i] = i; // Khud ko default answer set kiya
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &nei : adj[node]){
                // Seedha quiet array me minimum update karte chalo
                if(quiet[node] < quiet[nei]){
                    quiet[nei] = quiet[node];
                    res[nei] = res[node]; 
                }
                
                indeg[nei]--;
                if(indeg[nei] == 0) q.push(nei);
            }
        }

        return res;
    }
};