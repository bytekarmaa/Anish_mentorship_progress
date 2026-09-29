
class Solution {
public:

int solve(TreeNode* root, int val){
    if(root == nullptr) return 0;

    if(root->left == nullptr && root->right == nullptr) return val * 10 + root->val;

    return solve(root->left,val*10 + root->val) + solve(root->right,val*10 + root->val);
}

    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};