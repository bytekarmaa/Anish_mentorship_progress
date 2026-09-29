
class Solution {
public:

bool solve(TreeNode* root, long long &prev){
    if(root == nullptr) return true;

    bool left = solve(root->left,prev);
    if(left == false) return left;

    if(root->val <= prev) return false;

    prev = root->val;

    bool right = solve(root->right,prev);

    return left && right;
}

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return solve(root,prev);
    }
};