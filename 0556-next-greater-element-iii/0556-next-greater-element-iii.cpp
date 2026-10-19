class Solution {
public:
    int nextGreaterElement(int m) {
        string nums = to_string(m);
        int n = nums.size();
        int ind = -1;
        for(int i = n-2; i > -1; i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1) return -1;
        else {
            reverse(nums.begin() + ind + 1 , nums.end());
            for(int i = ind+1; i < n; i++){
                if(nums[i] > nums[ind]){
                    swap(nums[ind],nums[i]);
                    break;
                }
            }
        }
        
            long long ans = 0;
            for(int i = 0; i < n; i++){
                ans = ans*10 + (nums[i] - '0') % 10;
                if(ans > INT_MAX) return -1;
            }
            return ans;
        
    }
};