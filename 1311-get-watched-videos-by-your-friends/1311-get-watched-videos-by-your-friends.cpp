class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(id);
        visited[id] = true;


        while (level-- && !q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                for (int nei : friends[curr]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }


        unordered_map<string, int> freq;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (const string& video : watchedVideos[curr]) {
                freq[video]++;
            }
        }

        
        vector<pair<int, string>> res;
        res.reserve(freq.size());
        for (const auto& [video, count] : freq) {
            res.push_back({count, video});
        }

        sort(res.begin(), res.end());

        vector<string> ans;
        ans.reserve(res.size());
        for (const auto& [count, video] : res) {
            ans.push_back(video);
        }

        return ans;
    }
};