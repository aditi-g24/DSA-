class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= target; j++) {

                bool take = false;
                if (nums[i] <= j)
                    take = dp[i + 1][j - nums[i]];

                bool notTake = dp[i + 1][j];

                dp[i][j] = take || notTake;
            }
        }

        return dp[0][target];
    }
};