class Solution {
public:
    int solve(int ind, int curSum, int target, int n, vector<int>& nums){
        if(ind == n){
            if(curSum == target) return 1;
            return 0;
        }

        int plus = solve(ind + 1, curSum + nums[ind], target, n, nums);
        int minus = solve(ind + 1, curSum - nums[ind], target, n, nums);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return solve(0, 0,target, n, nums);
    }
};