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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            ++m[q.front()->val];
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        auto maxx=m.begin();
        for(auto itr=m.begin();itr!=m.end();++itr) {
            if(itr->second > maxx->second) maxx=itr;
        }
        vector<int> ans;
        for(auto itr=m.begin();itr!=m.end();++itr) {
            if(itr->second == maxx->second)
                ans.push_back(itr->first);
        }
        return ans;
    }
};