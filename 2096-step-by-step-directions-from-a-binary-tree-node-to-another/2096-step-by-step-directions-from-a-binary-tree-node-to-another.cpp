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
    bool dfs(string& str, TreeNode* root, int n) const {
        if (!root)
            return false;
        if(root->val==n)
            return true;
        if(root->left) {
            str.push_back('L');
            if(dfs(str, root->left,n))
                return true;
            str.pop_back();
        }
        if(root->right) {
            str.push_back('R');
            if(dfs(str, root->right, n))
                return true;
            str.pop_back();
        }
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(startValue==destValue)
            return "";
        string path1, path2;
        path1=path2="";
        dfs(path1, root, startValue);
        dfs(path2, root, destValue);
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(),path2.end());
        cout<<path1<<endl;
        cout<<path2<<endl;
        while(!path1.empty() && !path2.empty()) {
            if(path1.back()==path2.back()) {
                path1.pop_back(); path2.pop_back();
            }
            else break;
        }
        reverse(path2.begin(), path2.end());
        for(int i=0;i<path1.size();++i)
            path1[i]='U';
        return path1+path2;
    }
};