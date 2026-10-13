
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });

        for (int i = 0; i < nums.size(); i++) {
            if (i < (nums.size() + 1) / 2) {
                sum += 1LL * nums[i] * nums[i];
            }
            else {
                sum -= 1LL * nums[i] * nums[i];
            }
        }

        return sum;
    }
};
