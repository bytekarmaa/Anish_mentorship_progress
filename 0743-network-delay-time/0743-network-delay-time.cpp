class Solution {
public:

typedef pair<int,int> p;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<p> adj[n];

        for(auto ele : times){
            int u = ele[0] - 1;
            int v = ele[1] - 1;
            int wt = ele[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<p,vector<p>,greater<p>> pq;

        vector<int> dist(n,INT_MAX);

        dist[k - 1] = 0;

        pq.push({0,k - 1});

        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();

            int node = ele.second;
            int wt = ele.first;

            if(dist[node] < wt) continue;

            for(auto &ele : adj[node]){
                int neg = ele.first;
                int neg_wt = ele.second;

                if(dist[node] + neg_wt < dist[neg]){
                    dist[neg] = dist[node] + neg_wt;
                    pq.push({dist[neg],neg});
                }
            }
        }

        int res = *max_element(dist.begin(),dist.end());


        return (res == INT_MAX) ? -1 : res;
    }
};