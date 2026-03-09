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
    set<int> visited;
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& m, int idx, int start, int end) {
        assert(idx>=0);
        assert(idx<preorder.size());
        visited.insert(preorder[idx]);
        auto ptr=new TreeNode(preorder[idx]);
        int i=idx+1;
        for(i;i<preorder.size();i++) {
            if(m[preorder[i]]<m[preorder[idx]] && m[preorder[i]]>=start && m[preorder[i]]<end)
                break;
        }
        if(i<preorder.size() && visited.find(preorder[i])==visited.end()) {
            cout<<preorder[i]<<" is left child of "<<preorder[idx]<<endl;
            ptr->left=build(preorder, m, i, start, m[preorder[idx]]);
        }
        for(i=idx+1;i<preorder.size();i++) {
            if(m[preorder[i]]>m[preorder[idx]] && m[preorder[i]]>=start && m[preorder[i]]<end)
                break;
        }
        if(i<preorder.size() && visited.find(preorder[i])==visited.end()) {
            cout<<preorder[i]<<" is right child of "<<preorder[idx]<<endl;
            ptr->right=build(preorder, m, i, m[preorder[idx]]+1, end);
        }
        return ptr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return build(preorder, m, 0, 0, preorder.size());
    }
};