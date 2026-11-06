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
    bool remove(TreeNode* cur, int target) const {
        if(!cur) return false;
        bool leftnode=(cur->left)?remove(cur->left, target):false;
        bool rightnode=(cur->right)?remove(cur->right, target):false;
        if(leftnode) cur->left=nullptr;
        if(rightnode) cur->right=nullptr;
        if(!cur->left && !cur->right) {
            return cur->val==target;
        }
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool ret=remove(root, target);
        if(ret) return nullptr;
        return root;
    }
};