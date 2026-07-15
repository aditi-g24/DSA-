class Solution {
public:
    int solve(vector<int>& nums, vector<int>&temp){
        int n = temp.size();

        int prev = temp[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++){
            int rob = temp[i] + prev2;
            int notRob = prev;

            int curr = max(notRob, rob);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i = 0; i < n; i++){
            if(i!=(n-1)){
                temp1.push_back(nums[i]);
            }
            if(i!=0){
                temp2.push_back(nums[i]);
            }
        }

        return max(solve(nums,temp1), solve(nums,temp2));
    }
};