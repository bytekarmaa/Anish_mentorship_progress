class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0],nums[1]);

        int curr = 0;

        int next = max(nums[n-1],nums[n-2]);

        int next2 = nums[n-1];


        for(int i = n-3; i >= 0; i--){
            curr = max(nums[i] + next2, next);

            next2 = next;
            next = curr;
        }

        return curr;

    }
};