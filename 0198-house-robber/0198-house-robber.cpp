class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++){
            int rob = nums[i] + prev2;
            int notRob = prev;

            int curr = max(rob, notRob);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};