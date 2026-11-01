class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(nums[i] < mini){
                mini = nums[i];
            }
        }

        int ans = sum - (nums.size() * mini);
        return ans;
    }
};