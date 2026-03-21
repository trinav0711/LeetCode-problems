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
    void getSeq(TreeNode* root, vector<int>& v) {
        if(!root)
            return;
        if(!root->left && !root->right)
            v.push_back(root->val);
        if(root->left)
            getSeq(root->left, v);
        if(root->right)
            getSeq(root->right, v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        getSeq(root1, v1);
        getSeq(root2, v2);
        if(v1.size() != v2.size())
            return false;
        for(int i=0;i<v1.size();i++)
            if(v1[i]!=v2[i])
                return false;
        return true;
    }
};