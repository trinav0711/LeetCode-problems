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
    int best;
    int _max(TreeNode* cur) {
        if(!cur) return 0;
        int left=max(_max(cur->left), 0);
        int right=max(_max(cur->right), 0);
        best=max({best, cur->val+left+right});
        return cur->val+max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        best=INT_MIN;
        _max(root);
        return best;
    }
};