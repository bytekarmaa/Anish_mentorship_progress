class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            adj[u].push_back({v, cnt});
            adj[v].push_back({u, cnt});
        }

        queue<pair<int,int>> pq;
        pq.push({0, maxMoves});

        vector<int> movesLeft(n, -1);
        movesLeft[0] = maxMoves;

        while(!pq.empty()){
            auto val = pq.front();
            pq.pop();

            int node = val.first;
            int moves = val.second;

            if (moves < movesLeft[node]) continue;

            for(auto &e : adj[node]){
                int nei = e.first;
                int cnt = e.second;

                if(moves - cnt - 1 > movesLeft[nei]){
                    movesLeft[nei] = moves - cnt - 1;
                    pq.push({nei, movesLeft[nei]});
                }
            }
        }   

        int total = 0; 
        
        for(int i = 0; i < n; i++){
            if(movesLeft[i] != -1) total++;
        }

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int cnt = e[2];
            
            int from_u = max(0, movesLeft[u]);
            int from_v = max(0, movesLeft[v]);

            total += min(cnt, from_u + from_v); 
        }

        return total; 
    }
};