/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(root->left == nullptr && root->right == nullptr)
            return  targetSum == root->val;
        if(hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val))
            return true;
        return false;
    }
};