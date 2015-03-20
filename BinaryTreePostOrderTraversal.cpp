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
    vector<int> postorderTraversal(TreeNode *root) {
        //post order: left, right, then root
        vector<int> * postOrder = new vector<int>();
        postorderTraversal(root, postOrder);
        
        return *postOrder;
    }
    void postorderTraversal(TreeNode *root, vector<int> * postOrder) {
        if (root != nullptr && postOrder != nullptr){
            postorderTraversal(root->left, postOrder);
            postorderTraversal(root->right, postOrder);
            postOrder->push_back(root->val);
        }
    }
};