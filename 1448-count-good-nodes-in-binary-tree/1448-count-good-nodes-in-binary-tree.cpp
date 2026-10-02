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
    int ans = 0;

    void dfs(TreeNode* root, int curr){
        if(root == NULL){
            return;
        }
        
        if(root->val >= curr){
            ans++;
        }
        curr = max(curr,root->val);

        dfs(root->left, curr);
        dfs(root->right, curr);
        return;
    }
    int goodNodes(TreeNode* root) {
        int curr = root->val;
        dfs(root,curr);
        return ans;
    }
};