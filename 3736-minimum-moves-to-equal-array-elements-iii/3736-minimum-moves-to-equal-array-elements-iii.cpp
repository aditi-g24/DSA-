class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int ans = (nums[nums.size()-1] * nums.size()) - sum;
        return ans;
    }
};