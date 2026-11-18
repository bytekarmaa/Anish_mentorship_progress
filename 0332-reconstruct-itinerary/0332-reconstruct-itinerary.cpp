class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numTickets = 0;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numTickets = tickets.size();
        
		for (auto& t : tickets) {
            string u = t[0];
            string v = t[1];
            
			adj[u].push_back(v);
		}
        
        // Sort vertices in the adjacency list by lexical order
        for (auto &edges : adj) {
            sort(begin(edges.second), end(edges.second));
        }
        

        DFS("JFK");

        reverse(route.begin(),route.end());
        return route;
    }
    
    void DFS(string fromAirport) {
       
        
        vector<string>& neighbors = adj[fromAirport];
        
        // at the current layer, try its neighbors in the sorted order
        while(!neighbors.empty()) {
            
            string toAirport = *neighbors.begin();
            
            // remove ticket(route) from graph so that it won't be reused 
            neighbors.erase(neighbors.begin());
            
            DFS(toAirport);
                      
        }

         route.push_back(fromAirport);

         return;
        
      
    }
};