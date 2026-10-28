class Solution {
public:
    int ans = INT_MAX;
    vector<vector<vector<int>>> dp;

    void solve(vector<vector<int>>& grid, int i, int j, int xr) {
        int m = grid.size();
        int n = grid[0].size();

        xr ^= grid[i][j];

        if (dp[i][j][xr] == 1) return;
        dp[i][j][xr] = 1;

        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xr);
            return;
        }

        if (i + 1 < m)
            solve(grid, i + 1, j, xr);

        if (j + 1 < n)
            solve(grid, i, j + 1, xr);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(1024, 0)
        ));

        solve(grid, 0, 0, 0);
        return ans;
    }
};