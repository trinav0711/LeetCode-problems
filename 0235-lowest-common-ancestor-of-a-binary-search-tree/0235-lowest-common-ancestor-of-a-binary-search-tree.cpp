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
    TreeNode* lca;
    int found;
    bool getnode(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(lca) return false;
        if(!root) return false;
        bool ret=false;
        if(p && root->val==p->val) {
            --found;
            if(!found) return true;
            ret=true;
        }
        else if(q && root->val==q->val) {
            --found;
            if(!found) return true;
            ret=true;
        }
        bool left=getnode(root->left, p, q);
        if(ret && left) {
            lca=root; return true;
        }
        bool right=getnode(root->right, p, q);
        if(ret && right) {
            lca=root; return true;
        }
        if(left && right) {
            if(!lca) lca=root;
            return true;
        }
        return ret || left || right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca=nullptr; found=2;
        getnode(root, p, q);
        return lca;
    }
};