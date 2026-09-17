class Solution {
public:

vector<vector<int>> dp;

int memo(vector<vector<int>>& nums,int ind, int prev){
    if(ind >= nums.size()) return 0;

    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

    int take = 0;

    if(prev == -1 || nums[prev][1] < nums[ind][0]){
        take = 1 + memo(nums,ind+1,ind);
    }

    int skip = memo(nums,ind+1,prev);

    return dp[ind][prev+1] = max(take,skip);
}

    int findLongestChain(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        // dp.resize(n,vector<int> (n,-1));

        // return memo(nums,0,-1);



        // by tabulation

        vector<int> dp(n,1);

        int max_chain = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i][0] > nums[j][1]){
                    dp[i] = max(1+dp[j],dp[i]);
                }
            }
            max_chain = max(max_chain,dp[i]);
        }

        return max_chain;
    }
};