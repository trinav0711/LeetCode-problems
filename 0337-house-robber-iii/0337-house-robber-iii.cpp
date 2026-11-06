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
    int rob(TreeNode* root) {
        function<pair<int,int>(TreeNode*)> func=[&](TreeNode* cur) {
            if(!cur) return make_pair(0,0);
            auto leftnode=func(cur->left);
            auto rightnode=func(cur->right);
            int rob=cur->val+leftnode.second+rightnode.second;
            int notrob=max(leftnode.first,leftnode.second)+max(rightnode.first,rightnode.second);
            return make_pair(rob, notrob);
        };
        auto ret=func(root);
        return max(ret.first, ret.second);
    }
};