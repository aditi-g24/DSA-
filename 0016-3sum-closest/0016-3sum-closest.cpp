class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sum = 0;
        int closest = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];

                if (abs(target - sum) < diff) {
                    diff = abs(target - sum);
                    closest = sum;
                }

                if (sum < target) {
                    j++;
                }
                else if (sum > target) {
                    k--;
                }
                else {
                    return sum;
                }
            }
        }

        return closest;
    }
};