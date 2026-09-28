
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(!root) return res;

        queue<TreeNode*> pq;

        pq.push(root);

        while(!pq.empty()){
            int n = pq.size();
            int last_val = -1;

            for(int i = 0; i < n; i++){
                TreeNode* curr = pq.front();
                pq.pop();

                last_val = curr->val;

                if(curr->left) pq.push(curr->left);

                if(curr->right) pq.push(curr->right);
            }

            res.push_back(last_val);
        }

        return res;
    }
};