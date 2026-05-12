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
    void traverse(vector<int>& v, TreeNode* cur) {
        if(!cur)
            return;
        if(cur->left)
            traverse(v, cur->left);
        v.push_back(cur->val);
        if(cur->right)
            traverse(v, cur->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(ans, root);
        return ans;
    }
};