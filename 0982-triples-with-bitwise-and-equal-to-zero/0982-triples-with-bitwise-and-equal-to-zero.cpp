class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int max_val = 1 << 16;
        int full_mask = max_val - 1; // Ye tera ((1 << 16) - 1) hai
        
        // STEP 1: Frequencies store karna (Tera map wala pehla step)
        // Hum array use kar rahe hain kyunki array me SOS DP lagana easy hota hai
        vector<int> F(max_val, 0);
        for(int i = 0; i < n; i++) {
            F[nums[i]]++;
        }
        
        // STEP 2: SOS DP (Jaadui Thaila banana)
        // Ye code F array ko update kar dega taaki F[mask] me sirf uska nahi, 
        // balki uske saare submasks ka total count aa jaye.
        for(int i = 0; i < 16; i++) {
            for(int mask = 0; mask < max_val; mask++) {
                // Agar mask ki i-th bit 1 hai, toh apne twin (jiska bit 0 hai) ka data jod lo
                if(mask & (1 << i)) {
                    F[mask] += F[mask ^ (1 << i)];
                }
            }
        }
        
        int total = 0;
        
        // STEP 3: Tera original double loop check
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                
                int val = nums[i] & nums[j];
                
                // Zero banane ke liye, valid 3rd number wo hoga jisme sirf wahi bits 1 hon
                // jo 'val' me 0 hain. Toh hum exact flipped mask nikal rahe hain.
                int required_mask = val ^ full_mask;
                
                // Kyunki humara 'F' ab SOS DP se guzar chuka hai, 
                // ye hume direct saare valid 3rd numbers ka count de dega!
                total += F[required_mask];
            }
        }
        
        return total;
    }
};