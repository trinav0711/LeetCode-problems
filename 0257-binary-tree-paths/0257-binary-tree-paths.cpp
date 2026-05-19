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
    vector<string> paths;
    void traverse(TreeNode* root, vector<string>&& str) {
        if(!root)
            return;
        str.push_back(to_string(root->val));
        if(!root->left && !root->right) {
            string tmp="";
            for(int i=0;i<str.size()-1;++i) tmp+=(str[i]+"->");
            tmp+=str.back();
            paths.push_back(tmp);
        }
        if(root->left)
            traverse(root->left, forward<vector<string>>(str));
        if(root->right)
            traverse(root->right, forward<vector<string>>(str));
        str.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root, {});
        return paths;
    }
};