
class Solution {
public:
    vector<vector<vector<int>>> dp; 
    vector<pair<int,int>> cost;      // (zeros, ones)
    int n;

    int solve(int idx, int m, int n) {
        if (idx == this->n) return 0;          // no strings left

        if (dp[idx][m][n] != -1) return dp[idx][m][n];

        int zeros = cost[idx].first;
        int ones  = cost[idx].second;

        // Option 1: skip this string
        int skip = solve(idx + 1, m, n);

        // Option 2: take this string (only if budget allows)
        int take = 0;
        if (m >= zeros && n >= ones) {
            take = 1 + solve(idx + 1, m - zeros, n - ones);
        }

        return dp[idx][m][n] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        this->n = strs.size();

        cost.resize(this->n);
        for (int i = 0; i < this->n; i++) {
            int z = 0, o = 0;
            for (char c : strs[i]) {
                if (c == '0') z++;
                else o++;
            }
            cost[i] = {z, o};
        }

        // dp[idx][m][n] initialized to -1
        dp.assign(this->n, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return solve(0, m, n);
    }
};
