class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> indeg(n, 0);

        for(int i = 0; i < n; i++) {
            int neg = edges[i];
            if(neg != -1) indeg[neg]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        vector<bool> visited(n, false);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            visited[node] = true;

            int neg = edges[node];

            if(neg != -1) {
                indeg[neg]--;

                if(indeg[neg] == 0) {
                    q.push(neg);
                }
            }
        }

        // now just take the maxcomponent size
        
        int ans = -1;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {

                int cnt = 0;
                q.push(i);
                visited[i] = true;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    cnt++;

                    int neg = edges[node];

                    if(neg != -1 && !visited[neg]) {
                        visited[neg] = true;
                        q.push(neg);
                    }
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};