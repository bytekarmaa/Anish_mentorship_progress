class Solution {
public:

    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& indegree, int n) {
        queue<int> q;
        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);

            for(int v : adj[u]) {
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return res.size() == n ? res : vector<int>{};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // Step 1: assign unique group to -1 items
        for(int i = 0; i < n; i++) {
            if(group[i] == -1) {
                group[i] = m++;
            }
        }

        // Step 2: build graphs
        vector<vector<int>> itemAdj(n);
        vector<vector<int>> groupAdj(m);

        vector<int> itemIndegree(n, 0);
        vector<int> groupIndegree(m, 0);

        for(int i = 0; i < n; i++) {
            for(int prev : beforeItems[i]) {
                itemAdj[prev].push_back(i);
                itemIndegree[i]++;

                if(group[prev] != group[i]) {
                    groupAdj[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Step 3: topo sort items & groups
        vector<int> itemOrder = topoSort(itemAdj, itemIndegree, n);
        if(itemOrder.empty()) return {};

        vector<int> groupOrder = topoSort(groupAdj, groupIndegree, m);
        if(groupOrder.empty()) return {};

        // Step 4: group items
        unordered_map<int, vector<int>> groupToItems;

        for(int item : itemOrder) {
            groupToItems[group[item]].push_back(item);
        }

        // Step 5: build answer
        vector<int> result;

        for(int g : groupOrder) {
            for(int item : groupToItems[g]) {
                result.push_back(item);
            }
        }

        return result;
    }
};