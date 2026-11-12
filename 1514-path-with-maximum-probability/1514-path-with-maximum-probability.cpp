class Solution {
public:

unordered_map<int,vector<pair<int,double>>> mp;

typedef pair<double,int> p;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            mp[u].push_back({v,p});
            mp[v].push_back({u,p});
        }

        priority_queue<p> pq; 

        pq.push({1.0,start_node});

        vector<double> distProb(n, 0.0);
        distProb[start_node] = 1.0;

        while(!pq.empty())
        {
            auto [p,node] = pq.top();
            pq.pop();

            if(distProb[node] < p) continue;

            for(auto &ele : mp[node]){  
                int next_node = ele.first;
                double pro = ele.second;

                if(distProb[next_node] < pro * p) {
                    pq.push({pro*p,next_node});
                    distProb[next_node] = pro*p;
                }
            }
        }

        return distProb[end_node];
    }
};