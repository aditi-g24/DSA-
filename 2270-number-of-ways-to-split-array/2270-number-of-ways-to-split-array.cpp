class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int split = 0;
        int n = nums.size();
        long long totalsum = 0;
        long long leftsum = 0;

        for(int x : nums){
            totalsum += x;
        }

        for(int i = 0; i < n-1; i++){
            leftsum += nums[i];
            long long rightsum = totalsum - leftsum;
            if(leftsum >= rightsum){
                split++;
            }
        }
        return split;
    }
};