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
    pair<TreeNode*, int> solve(TreeNode* root){
        if(root == NULL){
            return{root,-1};
        }
        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.second > right.second){
            return {left.first, left.second + 1};
        }
        else if(right.second > left.second){
            return {right.first, right.second + 1};
        }
        else{
            return {root, right.second + 1};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto p = solve(root);
        return p.first;
    }
};