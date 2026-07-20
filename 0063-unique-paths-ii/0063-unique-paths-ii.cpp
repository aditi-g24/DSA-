class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // If start or destination is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if (i == m - 1 && j == n - 1)
                    continue;

                long long right = 0, down = 0;

                if (j + 1 < n)
                    right = dp[i][j + 1];

                if (i + 1 < m)
                    down = dp[i + 1][j];

                dp[i][j] = right + down;
            }
        }

        return dp[0][0];
    }
};