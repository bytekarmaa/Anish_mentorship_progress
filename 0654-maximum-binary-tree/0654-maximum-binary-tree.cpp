
class Solution {
public:

TreeNode* buildTree(int i, int j, vector<int> &nums){

    if(i > j) return nullptr;

    int ind = i;

    for(int k = i; k <= j; k++){
        if(nums[ind] < nums[k]){
            ind = k;
        }
    }

    TreeNode* root = new TreeNode(nums[ind]);

    root->left = buildTree(i,ind-1,nums);


    root->right = buildTree(ind+1,j,nums);

    return root;
}

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return buildTree(0,n-1,nums);
    }
};