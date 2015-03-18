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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, 0, postorder.size()-1, postorder.size()-1);
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int left, int right, int index){
        if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size()){
            printf("return null\n ");
            return nullptr;
        }
        if (right < 0 || left >= postorder.size() || right >= postorder.size() || left > right
            || index < 0){
            printf("return null\n ");
            return nullptr;
        }
        
        if (left == right){
            TreeNode * root = new TreeNode(inorder[left]);
            return root;
        }
        
        //TreeNode * root = new TreeNode(postorder[index+right-left]);
        TreeNode * root = new TreeNode(postorder[index]);
        //find root in inorder
        int count = 0;
        for (count = left; count <= right; count++){
            if (inorder[count] == root->val){
                break;
            }
        }
        //find root in postorder
        int count2 = 0;
        for (count2 = 0; count2 < postorder.size(); count2++){
            if (postorder[count2] == root->val){
                break;
            }
        }
        
        int rightLength = right - count;
        
        root->left = buildTree(inorder, postorder, left, count-1, count2-1-rightLength);
        root->right = buildTree(inorder, postorder, count+1, right, count2-1/*index-1*/);
        
        return root;
    }
    
};