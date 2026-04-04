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
    int ans=0;
public:
    int longestZigZag(TreeNode* root, int len=0, bool left=false, bool right=false) {
        if(!root)
            return ans;
        ans=max(ans, len);
        if(left) {
            if(root->left)
                longestZigZag(root->left, 1, true, false);
            if(root->right)
                longestZigZag(root->right, len+1, false, true);
        }
        else if(right) {
            if(root->left)
                longestZigZag(root->left, len+1, true, false);
            if(root->right)
                longestZigZag(root->right, 1, false, true);
        }
        else {
            if(root->left)
                longestZigZag(root->left, 1, true, false);
            if(root->right)
                longestZigZag(root->right, 1, false, true);
        }
        return ans;
    }
};