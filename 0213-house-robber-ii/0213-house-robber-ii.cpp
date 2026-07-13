class Solution {
public:

    int solve(vector<int>& arr, vector<int>& dp, int i){

        if(i == 0) return arr[0];
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int pick = arr[i] + solve(arr, dp, i-2);
        int notPick = solve(arr, dp, i-1);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> arr1(nums.begin(), nums.end()-1);
        vector<int> arr2(nums.begin()+1, nums.end());

        vector<int> dp1(arr1.size(), -1);
        vector<int> dp2(arr2.size(), -1);

        int case1 = solve(arr1, dp1, arr1.size()-1);
        int case2 = solve(arr2, dp2, arr2.size()-1);

        return max(case1, case2);
    }
};