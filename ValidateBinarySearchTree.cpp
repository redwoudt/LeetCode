/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        
        if (root->left && root->left->val >= root->val){
            return false;
        }
        
        if (root->right && root->right->val <= root->val){
            return false;
        }
        
        return (isValidBST(root->left, NULL, &root->val) && isValidBST(root->right, &root->val, NULL));
    }
    
    bool isValidBST(TreeNode *root, int * min, int * max){
        if (root == NULL) return true;
        
        
        if ((root->left && root->left->val >= root->val) || (min != NULL && root->left && root->left->val <= (*min))){
            return false;
        }
        
        if ((root->right && root->right->val <= root->val) || (max != NULL && root->right && root->right->val >= (*max))){
            return false;
        }
        
        return (isValidBST(root->left, min, &root->val) && isValidBST(root->right, &root->val, max));
        
    }
};