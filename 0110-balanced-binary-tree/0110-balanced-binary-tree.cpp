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
    int dfs(int& m, TreeNode* cur) {
        if(!cur) return 0;
        int left=cur->left?(1+dfs(m, cur->left)):0;
        int right=cur->right?(1+dfs(m, cur->right)):0;
        m=max(m, abs(left-right));
        return max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        int maxDiff=0;
        dfs(maxDiff, root);
        return maxDiff<=1;
    }
};