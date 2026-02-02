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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int c=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int s=q.size();
            for(int i=0;i<s;i++) {
                if(q.front()->left)
                    q.push(q.front()->left);
                else
                    return c+q.size();
                if(q.front()->right)
                    q.push(q.front()->right);
                else
                    return c+q.size();
                q.pop();
                c++;
            }
        }
        return c;
    }
};