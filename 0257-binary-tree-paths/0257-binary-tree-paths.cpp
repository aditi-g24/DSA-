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
    string path = "";
    vector<string> ans;

    void dfs(TreeNode* root, string &path, vector<string>& ans){
        if(root == NULL){
            return;
        }
        //abhi wala path len
        int len = path.size();
        if(path.empty()){
            path += to_string(root->val);
        }
        else{
            path += "->" + to_string(root->val);
        }

        //doing smthg abhi wale path ke saath
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            path.resize(len);
        }

        dfs(root->left,path,ans);
        dfs(root->right,path,ans);

        path.resize(len);
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,path,ans);
        return ans;
    }
};