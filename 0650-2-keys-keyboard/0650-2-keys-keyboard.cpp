class Solution {
public:

vector<vector<int>> dp;

int solve(int &n, int currLen, int prevLen){
    if(currLen == n) return 0;
    if(currLen > n)  return INT_MAX / 2;

    if(dp[currLen][prevLen] != -1) return dp[currLen][prevLen];

    int copy  = INT_MAX / 2;
    int paste = INT_MAX / 2;

    if(currLen != prevLen) copy  = solve(n, currLen, currLen);
    if(prevLen > 0)        paste = solve(n, currLen + prevLen, prevLen);

    return dp[currLen][prevLen] = 1 + min(copy, paste);
}

    int minSteps(int n) {
        
      dp.assign(n+1,vector<int> (n+1,-1));

      return solve(n,1,0);

    }
};