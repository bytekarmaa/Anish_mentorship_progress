class Solution {
public:

    vector<vector<int>> res;

    void left_right(deque<TreeNode*> &pq){
        vector<int> level;

        int n = pq.size();

        for(int i = 0; i < n; i++){
            TreeNode* curr = pq.front();
            pq.pop_front();

            level.push_back(curr->val);

            if(curr->left) pq.push_back(curr->left);
            if(curr->right) pq.push_back(curr->right);
        }

        res.push_back(level);
    }

    void right_left(deque<TreeNode*> &pq){
        vector<int> level;

        int n = pq.size();

        for(int i = 0; i < n; i++){
            TreeNode* curr = pq.back();
            pq.pop_back();

            level.push_back(curr->val);

            if(curr->right) pq.push_front(curr->right);
            if(curr->left) pq.push_front(curr->left);
        }

        res.push_back(level);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return res;

        deque<TreeNode*> pq;
        pq.push_back(root);

        bool flag = true;

        while(!pq.empty()){
            if(flag) left_right(pq);
            else right_left(pq);

            flag = !flag;
        }

        return res;
    }
};