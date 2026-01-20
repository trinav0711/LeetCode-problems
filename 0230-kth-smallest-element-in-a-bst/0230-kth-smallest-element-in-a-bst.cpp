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
    int ele=INT_MAX;
    void inOrder(TreeNode *root, int &k){
        if(!root)
            return;
        if(root->left && k)
            inOrder(root->left, k);
        if(k)
            k--;
        if(!k && ele==INT_MAX)
            ele=root->val;
        if(root->right && k)
            inOrder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ele;
    }
};