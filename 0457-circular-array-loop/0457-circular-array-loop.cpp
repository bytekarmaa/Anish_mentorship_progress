
class Solution {
public:
    int getNextIndex(vector<int>& nums, int curr, bool isForward) {
        bool currDirection = nums[curr] > 0;
        
        // 1. Direction check: saare jumps same sign ke hone chahiye
        if (currDirection != isForward) {
            return -1;
        }
        
        int n = nums.size();
        // Circular wrap-around (negative numbers ke liye +n zaroori hai)
        int nextIdx = ((curr + nums[curr]) % n + n) % n;
        
        // 2. Length > 1 check: agar khud par hi wapas aa gaya (self-loop), toh invalid hai
        if (nextIdx == curr) {
            return -1;
        }
        
        return nextIdx;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            bool isForward = nums[i] > 0;
            int slow = i;
            int fast = i;
            
            while (true) {
                // Slow moves 1 step
                slow = getNextIndex(nums, slow, isForward);
                if (slow == -1) break;
                
                // Fast moves 2 steps
                fast = getNextIndex(nums, fast, isForward);
                if (fast == -1) break;
                fast = getNextIndex(nums, fast, isForward);
                if (fast == -1) break;
                
                // Agar slow aur fast mil gaye, toh valid cycle mil gayi!
                if (slow == fast) {
                    return true;
                }
            }
        }
        
        return false;
    }
};