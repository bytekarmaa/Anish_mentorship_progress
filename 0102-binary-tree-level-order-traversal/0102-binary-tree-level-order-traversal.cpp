
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> pq;

        pq.push(root);

        while(!pq.empty()){
            int n = pq.size();

            vector<int> level;

            while(n--){
                TreeNode* curr = pq.front();
                pq.pop();

                level.push_back(curr->val);

                if(curr->left) pq.push(curr->left);

                if(curr->right) pq.push(curr->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};