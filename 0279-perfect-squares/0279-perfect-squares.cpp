// by memoization

// class Solution {
// public:

// int dp[10001];

// int solve(int n){
//     if(n == 0) return 0;

//     if(n < 0) return INT_MAX;

//     if(dp[n] != -1) return dp[n];

//     int least = INT_MAX;

//     for(int i = 1; i*i <= n; i++){
//         int res = 1 + solve(n-i*i);
//         least = min(res,least);
//     }

//     return dp[n] = least;
//  }

//     int numSquares(int n) {
//         memset(dp,-1,sizeof(dp));

//         return solve(n);
//     }
// };



// by tabulation


class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);

        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i],1 + dp[i-j*j]);
            }
        }


        return dp[n];


    }
};