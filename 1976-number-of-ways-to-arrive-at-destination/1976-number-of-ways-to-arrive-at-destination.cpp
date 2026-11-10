class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];

        for(auto &ele : roads){
            int u = ele[0];
            int v = ele[1];

            int t = ele[2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});

        }

       vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0] = 1;

        const int mod = 1e9 + 7;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        pq.push({0,0});

        dist[0] = 0;

        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();

            long long wt = val.first;
            int node = val.second;

            if(dist[node] < wt) continue;

            for(auto &ele : adj[node]){
                int new_node  = ele.first;
                int new_wt = ele.second;

                if(wt + new_wt < dist[new_node]){
                    dist[new_node] = wt + new_wt;
                    ways[new_node] = ways[node];
                    pq.push({dist[new_node],new_node});
                }

                else if(wt + new_wt == dist[new_node]){
                    ways[new_node] = (ways[node] + ways[new_node]) % mod;
                }
            }
        }


        return ways[n-1];

    }
};