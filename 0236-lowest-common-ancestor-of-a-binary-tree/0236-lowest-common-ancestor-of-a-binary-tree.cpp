
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;

        if(root == p || root == q) return root;

        TreeNode* left_child = lowestCommonAncestor(root->left,p,q);

        TreeNode* right_child = lowestCommonAncestor(root->right,p,q);

        if(left_child && right_child) return root;

        if(left_child) return left_child;
        else return right_child;
    }
};