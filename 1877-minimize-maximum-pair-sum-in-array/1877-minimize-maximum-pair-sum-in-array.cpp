class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;

        int j = nums.size() - 1;

        int max_sum = INT_MIN;

        while(i < j){
            max_sum = max(max_sum,(nums[i] + nums[j]));
            i++;
            j--;
        }

        return max_sum;
    }
};