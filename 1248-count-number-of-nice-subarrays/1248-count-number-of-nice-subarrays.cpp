class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ind;
        ind.push_back(-1);

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 != 0) ind.push_back(i);
        }

        ind.push_back(n);

        int m = ind.size() - 2;

        int i = 1;

        int count = 0;

        while(i + k - 1 <= m) {
            int left = ind[i] - ind[i-1];
            int right = ind[i+k] - ind[i + k - 1];

            count += (left * right);

            i++;

        }

        return count;


    }
};