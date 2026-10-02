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
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int targetSum, vector<int>& path, int& sum){
        if(root == NULL){
            return;
        }
        path.push_back(root->val);
        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
                sum-= root->val;
                path.pop_back();
                return;
            }
        }

        dfs(root->left,targetSum,path,sum);
        dfs(root->right, targetSum, path, sum);

        sum-=root->val;
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int sum = 0;
        dfs(root,targetSum,path,sum);
        return ans;
    }
};