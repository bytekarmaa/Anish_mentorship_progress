class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        // Constraints ke according nums[i] <= n hota h, so vector is faster than unordered_map
        vector<int> freq(n + 1, 0); 
        
        int left = 0, right = 0;
        int distinct_count = 0;
        int prefix_count = 0;
        int total_subarrays = 0;
        
        while (right < n) {
            // Naya element add karo
            if (freq[nums[right]] == 0) {
                distinct_count++;
            }
            freq[nums[right]]++;
            
            // Agar distinct elements K se zyada ho gaye, window ko aage badao
            if (distinct_count > k) {
                freq[nums[left]]--;
                left++;
                distinct_count--;
                prefix_count = 0; // Boundary shift ho gayi, prefix reset
            }
            
            // Shrink phase: Agar left wale element ki frequency > 1 h, 
            // iska matlab aage iska ek aur occurrence bacha hua h current window me.
            // Toh hum safely left ko aage bada sakte hain bina distinct_count kam kiye.
            while (freq[nums[left]] > 1) {
                freq[nums[left]]--;
                left++;
                prefix_count++; // Valid subarrays ka count badh gaya
            }
            
            // Jab exactly K distinct elements hon
            if (distinct_count == k) {
                total_subarrays += (1 + prefix_count);
            }
            
            right++;
        }
        
        return total_subarrays;
    }
};