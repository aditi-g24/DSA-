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
    pair<int,int> solve(TreeNode* node, int &ans){
        if(node == NULL){
            return {0,0};
        }
        auto left = solve(node->left,ans);
        auto right = solve(node->right,ans);

        int sum = left.first + right.first + node->val;
        int count = left.second + right.second + 1;

        if(node->val == sum/count){
            ans++;
        }

        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};