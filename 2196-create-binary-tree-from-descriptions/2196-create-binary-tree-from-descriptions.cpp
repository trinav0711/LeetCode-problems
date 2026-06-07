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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, int>> m; unordered_set<int> nodes;
        for(auto& v:descriptions) {
            if(m.find(v[0])==m.end()) {
                m[v[0]]=make_pair(-1,-1);
            }
            if(v[2]) m[v[0]].first=v[1];
            else m[v[0]].second=v[1];
            nodes.insert(v[0]); nodes.insert(v[1]);
        }
        for(auto& v:descriptions) {
            nodes.erase(v[1]);
        }
        assert(nodes.size()==1);
        TreeNode* root=new TreeNode(*nodes.begin());
        nodes.clear();
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            auto curr=q.front();
            if(m.find(curr->val)==m.end()) {
                q.pop(); continue;
            }
            if(m[curr->val].first!=-1) {
                auto tmp=new TreeNode(m[curr->val].first);
                curr->left=tmp;
                q.push(tmp);
            }
            if(m[curr->val].second!=-1) {
                auto tmp=new TreeNode(m[curr->val].second);
                curr->right=tmp;
                q.push(tmp);
            }
            q.pop();
        }
        return root;
    }
};