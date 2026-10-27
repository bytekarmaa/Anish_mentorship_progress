class Solution {
public:
   long long maximumSumOfHeights(vector<int>& maxHeights) {
    int n = maxHeights.size();
    vector<long long> prefix(n, 0), suffix(n, 0);
    stack<int> st;

    // 1. Calculate Prefix Sums
    for (int i = 0; i < n; i++) {
        while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            prefix[i] = (long long)(i + 1) * maxHeights[i];
        } else {
            int j = st.top();
            prefix[i] = prefix[j] + (long long)(i - j) * maxHeights[i];
        }
        st.push(i);
    }

    // Clear stack for suffix calculation
    while (!st.empty()) st.pop();

    // 2. Calculate Suffix Sums
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && maxHeights[st.top()] > maxHeights[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            suffix[i] = (long long)(n - i) * maxHeights[i];
        } else {
            int j = st.top();
            suffix[i] = suffix[j] + (long long)(j - i) * maxHeights[i];
        }
        st.push(i);
    }

    // 3. Find the maximum configuration sum
    long long maxSum = 0;
    for (int i = 0; i < n; i++) {
        long long currentSum = prefix[i] + suffix[i] - maxHeights[i];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
};