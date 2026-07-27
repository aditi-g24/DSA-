class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<long long>> dp(m,vector<long long>(n,0));

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else if(i == m-1 && j == n-1){
                    dp[i][j]=1;
                }
                else{
                    long long right = (j+1<n) ? dp[i][j+1] : 0;
                    long long down = (i+1 < m) ? dp[i+1][j] : 0;
                    dp[i][j] = right + down; 
                }
            }
        }
        return dp[0][0];
    }
};