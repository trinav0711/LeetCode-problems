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
class BSTIterator {
private:
    vector<int> inOrder;
    int cur;
    void dfs(TreeNode* root, vector<int>& v) {
        if(!root)
            return;
        if(root->left)
            dfs(root->left, v);
        v.push_back(root->val);
        if(root->right)
            dfs(root->right, v);
    }
public:
    BSTIterator(TreeNode* root): inOrder{}, cur{-1} {
        dfs(root, inOrder);
    }
    
    int next() {
        if(cur==inOrder.size()-1)
            return -1;
        return inOrder[++cur];
    }
    
    bool hasNext() {
        return cur==-1?inOrder.size()>0:cur<inOrder.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */