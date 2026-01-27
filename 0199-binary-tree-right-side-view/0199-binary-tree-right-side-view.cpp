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
    set<int> m;
    vector<int> ans;
    void traverse(TreeNode *node, int l) {
        if(!node)
            return;
        if(m.find(l)==m.end()){
            m.insert(l);
            ans.push_back(node->val);
        }
        traverse(node->right, l+1);
        traverse(node->left, l+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        traverse(root, 1);
        return ans;
    }
};