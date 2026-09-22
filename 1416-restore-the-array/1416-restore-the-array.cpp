class Solution {
public:

int n;

vector<int> dp;

int mod = 1e9 + 7;

int solve(string &s, int &k , int ind){
    if(ind == n) return 1;

    if(s[ind] == '0') return 0; // as we cannot split with leading zeroes

    if(dp[ind] != -1) return dp[ind];

    long long num = 0;

    int ways = 0;

    for(int i = ind; i < n; i++){
        num = num * 10 + (s[i] - '0');

        if(num > k) break;

        ways = (ways % mod + solve(s,k,i+1) % mod) % mod;
    }

    return dp[ind] = ways;
}

    int numberOfArrays(string s, int k) {
        n = s.size();

        dp.assign(n,-1);

        return solve(s,k,0);
    }
};