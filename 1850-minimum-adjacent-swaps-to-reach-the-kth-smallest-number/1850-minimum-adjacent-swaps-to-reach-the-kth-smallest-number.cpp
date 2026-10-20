
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;

        // Step 1: Find kth next permutation
        for (int i = 0; i < k; i++) {
            next_permutation(target.begin(), target.end());
        }

        // Step 2: Minimum adjacent swaps
        int n = num.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == target[i]) {
                continue;
            }

            // Find the required digit
            int j = i + 1;

            while (j < n && num[j] != target[i]) {
                j++;
            }

            // Bring it to position i using adjacent swaps
            while (j > i) {
                swap(num[j], num[j - 1]);
                ans++;
                j--;
            }
        }

        return ans;
    }
};
