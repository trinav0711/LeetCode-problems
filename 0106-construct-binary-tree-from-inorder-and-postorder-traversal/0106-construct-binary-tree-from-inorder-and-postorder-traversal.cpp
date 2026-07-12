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
    TreeNode* build(vector<int>& in, unordered_map<int,int>& m, int left, int right) const {
        if(left>right) return nullptr;
        int idx=left;
        for(int i=left+1;i<=right;++i) {
            if(m[in[i]] > m[in[idx]])
                idx=i;
        }
        auto newnode=new TreeNode(in[idx],build(in, m, left,idx-1),build(in, m,idx+1, right));
        return newnode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> post;
        for(int i=0;i<postorder.size();++i) {
            post[postorder[i]]=i;
        }
        return build(inorder, post, 0, inorder.size()-1);
    }
};