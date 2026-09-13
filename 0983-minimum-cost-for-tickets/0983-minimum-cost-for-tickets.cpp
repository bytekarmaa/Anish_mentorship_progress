// class Solution {
// public:

// int dp[370];


// int find_ind(vector<int>& days, int ind, int target) {
//     int low = ind, high = days.size() - 1;
//     int ans = days.size();  // default if no day >= target is found

//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (days[mid] >= target) {
//             ans = mid;      // potential answer, but let's find smaller one
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }

//     return ans;
// }

// int solve(vector<int> &days, vector<int> &cost, int ind){
//     if(ind >= days.size()) return 0;

//     if(dp[ind] != -1) return dp[ind];


//     int cost_day1 = cost[0] + solve(days,cost,ind+1);

//     int cost_day2 = cost[1] + solve(days,cost,find_ind(days,ind,days[ind] + 7));

//     int cost_day3 = cost[2] + solve(days,cost,find_ind(days,ind,days[ind] + 30));

//     return dp[ind] = min({cost_day1,cost_day2,cost_day3});

// }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = days.size();

//         memset(dp,-1,sizeof(dp));

//         return solve(days,costs,0);
//     }
// };



// by bottom up

class Solution {
public:

    int find_ind(vector<int>& days, int ind, int target) {
        int low = ind, high = days.size() - 1;
        int ans = days.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (days[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();
        vector<int> dp(n + 1, 0);   // dp[n] = 0

        for(int i = n - 1; i >= 0; i--) {

            int cost1 = costs[0] + dp[i + 1];

            int next7 = find_ind(days, i, days[i] + 7);
            int cost7 = costs[1] + dp[next7];

            int next30 = find_ind(days, i, days[i] + 30);
            int cost30 = costs[2] + dp[next30];

            dp[i] = min({cost1, cost7, cost30});
        }

        return dp[0];
    }
};
