// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         vector<vector<int>> dp(n + 2, vector<int>(2, 0));

//         for(int day = n - 1; day >= 0; day--){
//             for(int buy = 0; buy < 2; buy++){

//                 if(buy){
//                     int take_Stock = dp[day + 1][0] - prices[day];
//                     int skip_Stock = dp[day + 1][1];

//                     dp[day][buy] = max(take_Stock, skip_Stock);
//                 }
//                 else{
//                     int sell_Stock = prices[day] + dp[day + 2][1];
//                     int skip_Stock = dp[day + 1][0];

//                     dp[day][buy] = max(sell_Stock, skip_Stock);
//                 }
//             }
//         }

//         return dp[0][1];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> next(2, 0), next2(2, 0), curr(2, 0);

        for(int day = n - 1; day >= 0; day--){
            curr[1] = max(next[0] - prices[day], next[1]);
            curr[0] = max(prices[day] + next2[1], next[0]);

            next2 = next;
            next = curr;
        }

        return next[1];
    }
};

// dp memoized solution


// class Solution {
// public:

// int dp[5000][2];

// int solve(vector<int> &prices, int day, int n, int buy){
//     if(day >= n) return 0;

//     if(dp[day][buy] != -1) return dp[day][buy];

//     int profit = 0;

//     if(buy){
//         int take_Stock = solve(prices,day+1,n,!buy) - prices[day];

//         int skip_Stock = solve(prices,day+1,n,buy);

//         profit = max({profit,take_Stock,skip_Stock});
//     }

//     else{
//         int sell_Stock = prices[day] + solve(prices,day+2,n,!buy);

//         int skip_Stock = solve(prices,day+1,n,buy);

//         profit = max({profit,sell_Stock,skip_Stock});
//     }

//     return dp[day][buy] = profit;
// }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();

//         memset(dp,-1,sizeof(dp));

//         return solve(prices,0,n,true);
//     }
// };