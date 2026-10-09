class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9+7;
        int m = group.size();

        vector<vector<int>> next(minProfit+1,vector<int> (n+1,0));
        
        for(int i = 0; i <= n; i++){
            next[0][i] = 1;
        }

        for(int ind = m-1; ind >= 0; ind--){
            vector<vector<int>> curr(minProfit+1,vector<int> (n+1,0));

            for(int pro = 0; pro <= minProfit; pro++){
                for(int people = 0; people <= n; people++){
                    int take = 0;

                    if(people - group[ind] >= 0) take = next[max(0,pro - profit[ind])][people - group[ind]];

                    int skip = next[pro][people];

                    curr[pro][people] = (take % mod + skip % mod) % mod;
                }
            }

            next = curr;
        }

        return next[minProfit][n];
    }
};

// class Solution {
// public:

// int mod = 1e9 + 7;

// int dp[101][101][101];

// int m;

// int solve(int n, int minProfit,int ind,vector<int> &group,vector<int> &profit){

//     if(n < 0) return 0;

//     if(ind >= m){
//         return minProfit == 0;
//     }

//     if(dp[n][minProfit][ind] != -1) return dp[n][minProfit][ind];

//     int take = solve(n - group[ind],max(minProfit - profit[ind],0),ind+1,group,profit);

//     int skip = solve(n,minProfit,ind+1,group,profit);

//     return dp[n][minProfit][ind] = (take % mod + skip % mod) % mod;
// }

//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         m = group.size();
//         memset(dp,-1,sizeof(dp));

//         return solve(n,minProfit,0,group,profit);
//     }
// };