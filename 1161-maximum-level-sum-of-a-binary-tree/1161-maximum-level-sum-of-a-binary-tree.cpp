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
    int maxLevelSum(TreeNode* root) {
        pair<int, int> ans {INT_MAX,INT_MIN};
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()) {
            ++level;
            int s=q.size();
            int sum=0;
            while(s--) {
                sum+=q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(sum>ans.second) {
                ans.first=level;
                ans.second=sum;
            }
        }
        return ans.first;
    }
};