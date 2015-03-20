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
private:
    void reverse(vector<vector<int>> & v){
        int left = 0;
        int right = v.size()-1;
        while (left < right){
            vector<int> temp = v[left];
            v[left] = v[right];
            v[right] = temp;
            left++;
            right--;
        }
    }
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        //store nodes from left to right at each level
        //keep level pieces together in vector
        vector<vector<int>> ordered;
        
        //check null root
        if (root == nullptr){
            return ordered;
        }
        
        //keep level for each node
        unordered_map <TreeNode *, int> level;
        
        //do BFS to get to all nodes, pre-order traversal
        queue <TreeNode *> action;
        action.push(root);
        level[root] = 0;
        while (!action.empty()){
            TreeNode * current = action.front();
            action.pop();
            int currentLevel = level[current];
            if (currentLevel+1 > ordered.size()){
                vector<int> insert;
                insert.push_back(current->val);
                ordered.push_back(insert);
            }
            else{
                ordered[currentLevel].push_back(current->val);
            }
            if (current->left){
                level[current->left] = currentLevel+1;
                action.push(current->left);
            }
            if (current->right){
                level[current->right] = currentLevel+1;
                action.push(current->right);
            }
        }
        
        //reverse vector
        reverse(ordered);
        
        return ordered;
        
    }
};