class Solution {
public:

vector<vector<int>> dp;

int n;

int solve(vector<int> &nums, int ind, int target){
    if(ind == n){
        return target == 0;
    }

    if(dp[ind][target+2005] != -1) return dp[ind][target+2005];

    int total = solve(nums,ind+1,target - nums[ind]) + solve(nums,ind+1,target + nums[ind]);

    return dp[ind][target+2005] = total;

}

    int findTargetSumWays(vector<int>& nums, int target) {

        n = nums.size();
        
        dp.assign(n+1,vector<int> (target + 3005,-1));

        return solve(nums,0,target);

    }
};