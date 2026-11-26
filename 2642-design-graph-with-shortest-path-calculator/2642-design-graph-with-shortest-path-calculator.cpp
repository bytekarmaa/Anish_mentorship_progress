class Graph {
public:

typedef pair<long long,int> p;

unordered_map<int,vector<pair<int,int>>> mp;



int N;

    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto &ele : edges){
            int u = ele[0];
            int v = ele[1];

            int cost = ele[2];

            mp[u].push_back({v,cost});
        }
    }
    
    void addEdge(vector<int> ele) {
        int u = ele[0];
            int v = ele[1];

            int cost = ele[2];

            mp[u].push_back({v,cost});
    }
    
    int shortestPath(int node1, int node2) {
        int n = N;

        vector<long long> dist(n,INT_MAX);

        dist[node1] = 0;

        priority_queue<p,vector<p>,greater<p>> pq;

        pq.push({0,node1});

        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();

            int d = ele.first;
            long long node = ele.second;

            if(dist[node] < d) continue;

            for(auto &ele : mp[node]){
                int nei = ele.first;
                int cost = ele.second;

                if(dist[node] + cost < dist[nei]){
                    dist[nei] = cost + dist[node];
                    pq.push({dist[nei],nei});
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};
