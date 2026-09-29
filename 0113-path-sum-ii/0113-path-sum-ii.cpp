
class Solution {
public:
void check(TreeNode* root, vector<int>ref, vector<vector<int>> &ans, int sum){
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr){
        if(sum == root->val){
            ref.push_back(root->val);
            ans.push_back(ref);
        }
        return;
    }
    ref.push_back(root->val);
    check(root->left,ref,ans,sum-root->val);
    check(root->right,ref,ans,sum-root->val);

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        check(root,{},ans,targetSum);
        return ans;
    }
};