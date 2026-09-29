class Solution {
public:
    unordered_map<long long, int> mp;
    int count = 0;

    void solve(TreeNode* root, int targetSum, long long currSum) {
        if(root == nullptr) return;

        currSum += root->val;

        long long need = currSum - targetSum;
        if(mp.count(need))
            count += mp[need];

        mp[currSum]++;

        solve(root->left, targetSum, currSum);
        solve(root->right, targetSum, currSum);

        mp[currSum]--; // backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;          // base case
        solve(root, targetSum, 0);
        return count;
    }
};
