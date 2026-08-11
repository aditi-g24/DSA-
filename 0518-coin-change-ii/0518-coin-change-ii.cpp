class Solution {
public:
    int solve(int amount, vector<int>& coins, int ind, vector<vector<int>>& dp){
        int n = coins.size();
        if(ind == 0){
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = solve(amount, coins, ind - 1,dp);
        int take = 0;
        if(coins[ind] <= amount){
            take = solve(amount - coins[ind], coins, ind,dp);
        }

        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(amount, coins, n-1, dp);
    }
};