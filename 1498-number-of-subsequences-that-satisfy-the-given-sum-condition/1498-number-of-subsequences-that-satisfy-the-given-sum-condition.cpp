class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int count = 0;

        const int mod = 1e9 + 7;

        int i = 0;

        int j = n-1;

         vector<int> power(n);
        power[0] = 1;

        for(int i = 1; i < n; i++){
            power[i] = (2 * power[i-1]) % mod;
        }

        while(i <= j){
            if(nums[i] + nums[j] > target) j--;

            else{
                count = (count % mod + power[j-i] % mod) % mod;

                i++;
            }
        }

        return count;

        
    }
};