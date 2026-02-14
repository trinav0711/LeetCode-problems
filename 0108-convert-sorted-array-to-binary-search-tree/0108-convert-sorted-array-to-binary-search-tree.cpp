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
    TreeNode* create(TreeNode* root, vector<int>& nums, int left, int right) {
        if(left>=right)
            return root;
        int mid=(left+right)/2;
        cout<<"mid="<<mid<<"\n";
        root=new TreeNode(nums[mid]);
        if(left<mid)
            root->left=create(root->left, nums, left, mid);
        root->right=create(root->right, nums, mid+1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=nullptr;
        return root=create(root, nums, 0, nums.size());
    }
};