class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());


         vector<vector<int>> res;
        

        for(int i = 0; i < n-2; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;

            int left_sum = 0-nums[i];

            while(j < k){
                if(nums[j]+nums[k] == left_sum){
                    res.push_back({nums[i],nums[j],nums[k]});
                   
                    // skip duplicate j

                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicate `k`
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] > left_sum) k--;
                else j++;
            }
        }
        
       

        return res;
    }
};