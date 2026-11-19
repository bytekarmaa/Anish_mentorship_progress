class Solution {
public:

typedef pair<int,int> p;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        if(n == 1) return 0;

        queue<p> q;

        set<p> visited;

        for(int i = 0; i < n; i++){
            int mask = 1 << i;
            q.push({i,mask});
            visited.insert({i,mask});
        }


        int path = 0;

        int all_visited = (1 << n) - 1;

        while(!q.empty())
        {

            int size = q.size();

            while(size--){
                auto ele = q.front();
                q.pop();

                int node = ele.first;
                int mask = ele.second;

                if(mask == all_visited) return path;

                for(int &nei : graph[node]){
                    int curr_mask = 1 << nei;

                    int new_mask = curr_mask | mask;

                    if(!visited.count({nei,new_mask})) {
                        q.push({nei,new_mask});
                        visited.insert({nei,new_mask});
                    }
                }
            }

             path++;

        }

        return -1;
    }
};