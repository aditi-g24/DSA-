class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int right = 1e9;
                    int down = 1e9;
                    if(j+1 < n) {
                        right = dp[i][j+1];
                    }
                    if(i+1 < m){
                        down = dp[i+1][j];
                    }
                    dp[i][j] = grid[i][j] + min(right,down);
                }
            }
        }
        return dp[0][0];
    }
};