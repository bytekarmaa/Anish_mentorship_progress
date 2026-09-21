class Solution {
public:

const int M = 1e9 + 7;

int dp[100001][2][3];

int solve(int n, int absent, int consecutiveLate){
    if(absent > 1 || consecutiveLate > 2) return 0;

    if(n == 0) return 1;

    if(dp[n][absent][consecutiveLate] != -1) return dp[n][absent][consecutiveLate];

    int a = solve(n-1,absent+1,0);
    int l = solve(n-1,absent,consecutiveLate+1);
    int p = solve(n-1,absent,0);

    return dp[n][absent][consecutiveLate] = ((a+l) % M + p) % M;
}

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));

        return solve(n,0,0);
    }
};