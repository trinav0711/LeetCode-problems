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
    TreeNode *  findMin( TreeNode*  root ){
        while ( root ->left ){
            root = root->left ;

        }
        return  root ;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( root==NULL ) return  NULL ;
        if ( key <root->val){
            root-> left = deleteNode( root ->left , key );
            
        }
        else if ( key > root-> val){
            root-> right = deleteNode ( root -> right, key );
        }
        else {
            if ( root-> left==NULL ){
                return  root->right ;
            }
            else if ( root ->right ==NULL){
                return  root -> left ;

            }
            else {
                TreeNode*  temp = findMin(root->right);
                root->val = temp->val ;
                root ->right = deleteNode(root->right , temp->val  );

            }
        }
        return root ; 
    }
};