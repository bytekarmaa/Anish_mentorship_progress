class Solution {
public:


int n;

// int memo(vector<int> &nums, int ind, int n){
//     if(ind >= n) return 0;

//     if(dp[ind] != -1) return dp[ind];

//     return dp[ind] = max(nums[ind] + solve(nums,ind+2,n) , solve(nums,ind+1,n));
// }

int tabu(vector<int> &nums, int ind, int end){


        vector<int> dp(nums.begin(),nums.end());

        dp[end-1] = max(nums[end],nums[end-1]);

        for(int i = end - 2; i >= ind; i--){
            dp[i] = max(dp[i+1],nums[i] + dp[i+2]);
        }

        return dp[ind];
}

    int rob(vector<int>& nums) {
        n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0],nums[1]);

        int case1 = tabu(nums,0,n-2);

        int case2 = tabu(nums,1,n-1);

        return max(case1,case2);
    }
};