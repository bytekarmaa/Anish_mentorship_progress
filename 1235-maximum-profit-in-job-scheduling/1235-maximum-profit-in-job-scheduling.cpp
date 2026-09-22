class Solution {
public:

int n;
vector<int> dp;

int get_nextInd(vector<vector<int>> &nums, int lo, int val){
    int hi = n - 1;

    int resInd = -1;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(nums[mid][0] < val) lo = mid + 1;
        
        else {
            resInd = mid;
             hi = mid - 1;
        }
    }

    return (resInd == -1) ? n : resInd;
}

int solve(vector<vector<int>> &nums, int ind){
    if(ind >= n) return 0;

    if(dp[ind] != -1) return dp[ind];

    int nextInd = get_nextInd(nums,ind,nums[ind][1]);

    int take = nums[ind][2] + solve(nums, nextInd);

    int skip = solve(nums,ind+1);

    return dp[ind] = max(take,skip);
}

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         n = startTime.size();
         dp.assign(n,-1);

         vector<vector<int>> nums(n,vector<int> (3,0));

         for(int i = 0; i < n; i++){
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
         }

         sort(nums.begin(),nums.end());

         return solve(nums,0);
    }
};