class Solution {
public:

int n;

int dp[21][10001];

int solve(vector<int> &rods, int ind, int diff){
    if(ind == n){
        if(diff == 0) return 0;

        else return -5000;
    }

    if(dp[ind][diff + 5000] != -1) return dp[ind][diff + 5000];

    int rod1 = rods[ind] + solve(rods,ind+1,diff + rods[ind]);

    int rod2 = rods[ind] + solve(rods,ind+1,diff - rods[ind]);

    int skip = solve(rods,ind+1,diff);


    return dp[ind][diff + 5000] = max({rod1,rod2,skip});
}

    int tallestBillboard(vector<int>& rods) {
       n = rods.size();

       memset(dp,-1,sizeof(dp));

       return solve(rods,0,0) / 2;
    }
};