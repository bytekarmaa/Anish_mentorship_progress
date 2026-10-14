class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> ind = {-1};

        for(int i = 0; i < n; i++)
            if(nums[i] == 1) ind.push_back(i);

        ind.push_back(n);

        int m = ind.size() - 2;
        int count = 0;

        if(goal == 0) {
            for(int i = 1; i < ind.size(); i++) {
                int len = ind[i] - ind[i-1] - 1;
                count += len * (len + 1) / 2;
            }
            return count;
        }

        for(int i = 1; i + goal - 1 <= m; i++) {
            int left = ind[i] - ind[i-1];
            int right = ind[i+goal] - ind[i+goal-1];
            count += left * right;
        }

        return count;
    }
};