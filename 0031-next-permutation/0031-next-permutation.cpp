class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i = n-2; i > -1; i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1) reverse(nums.begin(),nums.end());
        else {
            reverse(nums.begin() + ind + 1 , nums.end());
            for(int i = ind+1; i < n; i++){
                if(nums[i] > nums[ind]){
                    swap(nums[ind],nums[i]);
                    break;
                }
            }
        }
        return;
    }
};