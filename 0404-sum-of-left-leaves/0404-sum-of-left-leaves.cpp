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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int ans=0;
        while(!q.empty()) {
            auto [ptr, left]=q.front();
            if(left && !ptr->left && !ptr->right) ans+=(ptr->val);
            if(ptr->left)
                q.push({ptr->left, true});
            if(ptr->right)
                q.push({ptr->right, false});
            q.pop();
        }
        return ans;
    }
};