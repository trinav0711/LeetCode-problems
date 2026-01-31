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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()) {
            int s=q.size();
            vector<int> tmp;
            for(int i=0;i<s;i++){
                auto itr=q.front();
                tmp.push_back(itr->val);
                if(itr->left)
                    q.push(itr->left);
                if(itr->right)
                    q.push(itr->right);
                q.pop();
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};