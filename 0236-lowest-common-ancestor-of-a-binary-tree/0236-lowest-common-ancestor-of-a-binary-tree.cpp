/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* target;
    bool found;
    void dfs(vector<TreeNode*>& s, TreeNode* root) {
        if(!root)
            return;
        s.push_back(root);
        if(root->val==target->val) {
            found=true;
            return;
        }
        if(root->left && !found)
            dfs(s, root->left);
        if(root->right && !found)
            dfs(s, root->right);
        if(!found)
            s.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1, v2;
        target=p;
        found=false;
        dfs(v1, root);
        target=q;
        found=false;
        dfs(v2, root);
        if(v1.size()!=v2.size()) {
            auto& ref=v1.size()>v2.size()?v1:v2;
            while(v1.size()!=v2.size())
                ref.pop_back();
        }
        while(!v1.empty() && !v2.empty()) {
            if(v1.back()->val==v2.back()->val)
                return v1.back();
            v1.pop_back();
            v2.pop_back();
        }
        return root;
    }
};