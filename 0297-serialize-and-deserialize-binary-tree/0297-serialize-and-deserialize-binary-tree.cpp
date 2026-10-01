
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";

        string ref = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();


            if(node == nullptr) ref += "#,";

            else{
                ref += (to_string(node->val) + ',');

                q.push(node->left);
                q.push(node->right);
            }

        }

        return ref;
    }



    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        stringstream ss(data);

        string tem;

        getline(ss,tem,',');

        TreeNode* root = new TreeNode(stoi(tem));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(ss,tem,',');

            if(tem == "#") node->left == nullptr;
            else {
                node->left = new TreeNode(stoi(tem));
                q.push(node->left);
            }


            getline(ss,tem,',');

            if(tem == "#") node->right = nullptr;

            else {
                node->right = new TreeNode(stoi(tem));
                q.push(node->right);
            }
        }

        return root;
    }
};
