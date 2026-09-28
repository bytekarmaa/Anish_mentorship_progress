
class Solution {
public:

    unordered_map<TreeNode* , TreeNode*> parent;

    void findParent(TreeNode* root){

        if(root->left){
            parent[root->left] = root;

            findParent(root->left);
        }

        if(root->right){
            parent[root->right] = root;

            findParent(root->right);
        }

        return;
    }

    void bfs(TreeNode* target, int k, vector<int> &res){
        unordered_set<int> visited;

        queue<TreeNode*> q;

        q.push(target);

        while(!q.empty()){
            
            int n = q.size();


            if(!k) break;

            while(n--){
                TreeNode* curr = q.front();
                  q.pop();

                   visited.insert(curr->val);

                   // left child

                   if(curr->left && !visited.count(curr->left->val)){
                    q.push(curr->left);
                   }

                   // right child

                   if(curr->right && !visited.count(curr->right->val)){
                    q.push(curr->right);
                   }

                   // parent

                   if(parent.count(curr) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                   }

            }


            k--;
 
        }

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

          findParent(root);

          vector<int> res;

          bfs(target,k,res);

          return res;  

    }
};