class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int,int> mp;

        int maxLen = 0;
        int i = 0, j = 0;

        while(j < n) {
            mp[nums[j]]++;

            while(mp.rbegin()->first - mp.begin()->first > limit) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};