class Solution {
public:

int n;

vector<vector<int>> dp;

int solve(vector<int> &coins, int amount, int ind){
    if(amount == 0) return 1;

    if(ind >= n || amount < 0) return 0;

    if(dp[ind][amount] != -1) return dp[ind][amount];

    int take = solve(coins,amount - coins[ind],ind);
    int skip = solve(coins,amount,ind+1); 

    return dp[ind][amount] = take + skip;
}

    int change(int amount, vector<int>& coins) {
        
        n = coins.size();

        dp.assign(n,vector<int> (amount+1,-1));

        return solve(coins,amount,0);
    }
};