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
    int good;
    void traverse(TreeNode* root, int m) {
        if(m<=root->val) {
            ++good;
            m=max(m, root->val);
        }
        if(root->left)
            traverse(root->left, m);
        if(root->right)
            traverse(root->right, m);
    }
public:
    int goodNodes(TreeNode* root) {
        good=0;
        traverse(root, INT_MIN);
        return good;
    }
};