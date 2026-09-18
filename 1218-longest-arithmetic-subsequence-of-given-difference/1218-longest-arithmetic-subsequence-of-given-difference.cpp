class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int> mp;

        int maxLen = 1;

        for(int i = 0; i < n; i++){
            if(mp.count(arr[i] - difference)) maxLen = max(maxLen,1 + mp[arr[i] - difference]);

            mp[arr[i]] = 1 + mp[arr[i] - difference];
        }

        return maxLen;
    }
};