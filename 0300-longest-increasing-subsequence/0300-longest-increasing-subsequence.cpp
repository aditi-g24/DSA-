class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        if (dp[ind] != -1) return dp[ind];

        int maxi = 1;

        for (int prev = 0; prev < ind; prev++) {
            if (nums[ind] > nums[prev]) {
                maxi = max(maxi, 1 + solve(nums, prev, dp));
            }
        }

        return dp[ind] = maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(nums, i, dp));
        }

        return ans;
    }
};