class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int rob = nums[i];
            if(i > 1){
                rob += prev2;
            }
            int notRob = prev + 0;
            int curr = max(rob, notRob);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};