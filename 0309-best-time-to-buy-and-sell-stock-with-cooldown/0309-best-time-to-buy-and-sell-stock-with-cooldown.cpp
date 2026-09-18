// dp memoized solution


class Solution {
public:

int dp[5000][2];

int solve(vector<int> &prices, int day, int n, int buy){
    if(day >= n) return 0;

    if(dp[day][buy] != -1) return dp[day][buy];

    int profit = 0;

    if(buy){
        int take_Stock = solve(prices,day+1,n,!buy) - prices[day];

        int skip_Stock = solve(prices,day+1,n,buy);

        profit = max({profit,take_Stock,skip_Stock});
    }

    else{
        int sell_Stock = prices[day] + solve(prices,day+2,n,!buy);

        int skip_Stock = solve(prices,day+1,n,buy);

        profit = max({profit,sell_Stock,skip_Stock});
    }

    return dp[day][buy] = profit;
}

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        memset(dp,-1,sizeof(dp));

        return solve(prices,0,n,true);
    }
};