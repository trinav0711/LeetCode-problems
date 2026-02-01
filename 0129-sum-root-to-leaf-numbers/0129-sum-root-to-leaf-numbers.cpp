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
    int sum;
    void traverse(TreeNode* root, string str) {
        if(!root->left && !root->right) {
            sum+=(stoi(str+to_string(root->val)));
            return;
        }
        if(root->left)
            traverse(root->left, str+to_string(root->val));
        if(root->right)
            traverse(root->right, str+to_string(root->val));
    }
public:
    int sumNumbers(TreeNode* root) {
        sum=0;
        traverse(root, "");
        return sum;
    }
};