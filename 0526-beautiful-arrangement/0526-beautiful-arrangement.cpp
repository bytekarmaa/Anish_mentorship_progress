class Solution {
public:

int N;

vector<int> dp;

int solve(int n, int mask){
    if(n == 0) return 1;

    if(dp[mask] != -1) return dp[mask];

    int count = 0;


    for(int i = 1; i <= N; i++){
        int bit = (1 << (i-1));

        if(!(mask & bit) && (n % i == 0 || i % n == 0)){
            count += solve(n-1,(mask | bit));
        }
    }


    return dp[mask] = count;
}

    int countArrangement(int n) {
        N = n;

        dp.resize((1 << n),-1);

        int bitMask = 0;

        return solve(n,bitMask);

    }
};