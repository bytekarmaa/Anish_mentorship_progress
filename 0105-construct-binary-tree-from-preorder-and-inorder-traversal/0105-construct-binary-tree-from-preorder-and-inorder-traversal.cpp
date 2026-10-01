
class Solution {
public:

TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int lo, int hi, int &ind){
    if(lo > hi) return nullptr;

    int i = lo;

    while(i <= hi){
        if(inorder[i] == preorder[ind]){
            break;
        }
        i++;
    }

    TreeNode* root = new TreeNode(inorder[i]);

    ind++;

    root->left = solve(preorder,inorder,lo,i-1,ind);

    root->right = solve(preorder,inorder,i+1,hi,ind);

    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        int ind = 0;

        return solve(preorder,inorder,0,n-1,ind);
    }
};