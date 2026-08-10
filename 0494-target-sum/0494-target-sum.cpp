class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }

        if(abs(target) > totalSum) return 0;
        if((totalSum - target)%2 != 0) return 0;
        int subsetSum = (totalSum - target)/2;

        vector<vector<int>> dp(n, vector<int>(subsetSum + 1, 0));

        if(nums[0]==0){
            dp[0][0] = 2;
        }
        else dp[0][0] = 1;

        if(nums[0]!=0 && nums[0] <= subsetSum){
            dp[0][nums[0]] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int t = 0; t <= subsetSum; t++){
                int notTake = dp[ind - 1][t];
                int take = 0;
                if(nums[ind] <= t){
                    take = dp[ind - 1][t - nums[ind]];
                }
                dp[ind][t] = take + notTake;
            }
        }

        return dp[n-1][subsetSum];
    }
};