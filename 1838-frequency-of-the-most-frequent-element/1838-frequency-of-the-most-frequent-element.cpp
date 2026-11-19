class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long currentSum = 0; 
        int left = 0;
        int ans = 1;

        for (int right = 0; right < nums.size(); right++) {
            long long target = nums[right];
            currentSum += target;

            // Cost to make all elements in [left..right] equal to target
            while (target * (right - left + 1) - currentSum > k) {
                currentSum -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};