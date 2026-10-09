class Solution {
public:

int mod = 1e9 + 7;

int dp[101][101][101];

int m;

int solve(int n, int minProfit,int ind,vector<int> &group,vector<int> &profit){

    if(n < 0) return 0;

    if(ind >= m){
        return minProfit == 0;
    }

    if(dp[n][minProfit][ind] != -1) return dp[n][minProfit][ind];

    int take = solve(n - group[ind],max(minProfit - profit[ind],0),ind+1,group,profit);

    int skip = solve(n,minProfit,ind+1,group,profit);

    return dp[n][minProfit][ind] = (take % mod + skip % mod) % mod;
}

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        m = group.size();
        memset(dp,-1,sizeof(dp));

        return solve(n,minProfit,0,group,profit);
    }
};