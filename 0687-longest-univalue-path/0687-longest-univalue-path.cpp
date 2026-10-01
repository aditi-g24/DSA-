class Solution {
public:
    int ans = 0;

    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int leftPath = 0;
        int rightPath = 0;

        if (root->left && root->left->val == root->val)
            leftPath = left + 1;

        if (root->right && root->right->val == root->val)
            rightPath = right + 1;

        ans = max(ans, leftPath + rightPath);

        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return ans;
    }
};