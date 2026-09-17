class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % 2 != 0) return false;

        sum /= 2;

        vector<int> dp(sum + 1,0);

        dp[0] = true;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = sum; j >= 1; j--){
                if(dp[j] == true || j - nums[i] < 0) continue;

                else dp[j] = (dp[j] || dp[j - nums[i]]);
            }
        }

        return dp[sum];
    }
};