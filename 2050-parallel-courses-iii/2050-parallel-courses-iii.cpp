class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);

        for(auto &ele : relations){
            int u = ele[0] - 1;
            int v = ele[1] - 1;

            adj[u].push_back(v);

            indeg[v]++;
        }

        vector<int> maxTime(n,0);
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &nei : adj[node]){
                if(maxTime[nei] < maxTime[node] + time[nei]){
                    maxTime[nei] = maxTime[node] + time[nei];
                }

                indeg[nei]--;

                if(indeg[nei] == 0) q.push(nei);
            }
        }

        return *max_element(maxTime.begin(),maxTime.end());

    }
};