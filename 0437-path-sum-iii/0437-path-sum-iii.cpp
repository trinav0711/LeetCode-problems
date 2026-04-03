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
    int ans;
    int sum;
    void dfs(TreeNode* root, vector<long>& v, long last=0) {
        if(!root)
            return;
        auto tmp=root->val+last;
        for(auto x:v)
            if(tmp-x==sum)
                ++ans;
        if(tmp==sum)
            ++ans;
        v.push_back(tmp);
        if(root->left)
            dfs(root->left, v, tmp);
        if(root->right)
            dfs(root->right, v, tmp);
        v.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        sum=targetSum;
        ans=0;
        vector<long> vt;
        dfs(root, vt);
        return ans;
    }
};