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
    TreeNode* lca = nullptr;
    pair<bool, bool> pr={false, false};
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        cout<<"Value="<<root->val<<"\n";
        TreeNode *tmp1,*tmp2,*tmp;
        tmp1=tmp2=tmp=nullptr;
        if(root->left)
            tmp1=lowestCommonAncestor(root->left, p, q);   
        if(root->right)
            tmp2=lowestCommonAncestor(root->right, p, q);
        if(root==p || root==q) {
            if(root==p)
                pr.first=true;
            else
                pr.second=true;
            tmp=root;
        }
        if(!lca && pr.first && pr.second) {
            if(tmp1 && tmp2)
                lca=root;
            else if(tmp && (tmp1 || tmp2))
                lca=root;
        }
        return lca?lca:(tmp?tmp:(tmp1?tmp1:tmp2));
    }
};