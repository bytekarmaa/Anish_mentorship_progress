class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
          int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int day = n - 1; day >= 0; day--){
            for(int buy = 0; buy < 2; buy++){

                if(buy){
                    int take_Stock = dp[day + 1][0] - prices[day];
                    int skip_Stock = dp[day + 1][1];

                    dp[day][buy] = max(take_Stock, skip_Stock);
                }
                else{
                    int sell_Stock = prices[day] + dp[day + 1][1] - fee;
                    int skip_Stock = dp[day + 1][0];

                    dp[day][buy] = max(sell_Stock, skip_Stock);
                }
            }
        }

        return dp[0][1];
    }
};


// class Solution {
// public:


// int dp[50001][2];


// int solve(vector<int>& prices,int ind, bool buy, int &fee){
//     if(ind >= prices.size()) return 0;

//     if(dp[ind][buy] != -1) return dp[ind][buy];

//     int profit = 0;


//     if(buy){ // turn to buy stock
//         int take = solve(prices,ind+1,!buy,fee) - prices[ind];
//         int not_take = solve(prices,ind+1,buy,fee);

//         profit = max(take,not_take);
//     }

//     else{
//         int sell = prices[ind] + solve(prices,ind+1,!buy,fee) - fee;

//         int not_sell = solve(prices,ind+1,buy,fee);

//          profit = max(sell,not_sell);
//     }


//     return dp[ind][buy] = profit;
// }


//     int maxProfit(vector<int>& prices, int fee) {
//         int n = prices.size();

//         memset(dp,-1,sizeof(dp));

//         return solve(prices,0,true,fee);
//     }
// };