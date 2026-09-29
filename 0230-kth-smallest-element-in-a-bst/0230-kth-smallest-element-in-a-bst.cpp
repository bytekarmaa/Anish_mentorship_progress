
class Solution {
public:
    int check(TreeNode* root, int& count, int k) {
        if (root == NULL)
            return -1;
            
        int x =  check(root->left, count, k);
        if(x!= -1) return x;
        count++;
        if (count == k) return root->val;
        return check(root->right, count, k);
       
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
       return check(root, count, k);
       
    }
};