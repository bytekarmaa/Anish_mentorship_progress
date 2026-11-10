class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto &f : flights){
            int u = f[0];
            int v = f[1];
            int wt = f[2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,int>> pq;

        pq.push({src,0});

        vector<int> dist(n,INT_MAX);

        dist[src] = 0;

        int steps = 0;

        while(!pq.empty() && steps <= k){
            int size = pq.size();

            while(size--){
                auto val = pq.front();
                pq.pop();

                int node = val.first;
                int wt = val.second;

                for(auto &ele : adj[node]){
                    int new_node = ele.first;
                    int new_wt = ele.second;

                    if(wt + new_wt < dist[new_node]){
                        dist[new_node] = wt + new_wt;
                        pq.push({new_node,dist[new_node]});
                    }
                }
            }

            steps++;
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};