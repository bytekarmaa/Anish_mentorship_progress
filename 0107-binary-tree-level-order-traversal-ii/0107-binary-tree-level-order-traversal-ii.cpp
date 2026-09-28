
class Solution {
public:

int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int n = levels(root);
        res.resize(n);

        int lev = n-1;

        queue<TreeNode*> pq;

        pq.push(root);

        while(!pq.empty()){
            int size = pq.size();

            for(int i = 0; i < size; i++){
                TreeNode* curr = pq.front();
                pq.pop();

                res[lev].push_back(curr->val);

                if(curr->left) pq.push(curr->left);
                if(curr->right) pq.push(curr->right);
            }

            lev--;
        }

        return res;
    }
};