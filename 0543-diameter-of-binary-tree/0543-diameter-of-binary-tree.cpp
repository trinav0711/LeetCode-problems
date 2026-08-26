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
private:
    int ans;
    int _max(TreeNode *root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        int left=root->left?1+_max(root->left):0;
        int right=root->right?1+_max(root->right):0;
        ans=max(ans, left+right);
        return max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        _max(root);
        return ans;
    }
};