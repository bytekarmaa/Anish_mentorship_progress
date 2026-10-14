

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();

        int mx_ones = INT_MIN;

        while(j < n){
            if(nums[j] == 0) zero++;
    
            while(zero > k){   // moving to just next consecutive subarray
                if(nums[i] == 0) zero--;
                i++;
            }

               if(zero == k){
                int window_size = j-i+1;
                mx_ones = max(mx_ones,window_size);
            }

            j++;
        }

        if(mx_ones == INT_MIN) return n;

        return mx_ones;
    }
};