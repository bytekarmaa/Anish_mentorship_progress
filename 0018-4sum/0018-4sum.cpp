class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 🔹 Early pruning for i
            long long min1 = 1LL * nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (min1 > target) break;  // too large, no point continuing
            long long max1 = 1LL * nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (max1 < target) continue; // too small, move i forward

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 🔹 Early pruning for j
                long long min2 = 1LL * nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (min2 > target) break;
                long long max2 = 1LL * nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (max2 < target) continue;

                int l = j + 1, r = n - 1;
                long long toSearch = 1LL * target - nums[i] - nums[j];

                while (l < r) {
                    long long sum = 1LL * nums[l] + nums[r];

                    if (sum == toSearch) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;

                        // Skip duplicates for l and r
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if (sum < toSearch) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};
