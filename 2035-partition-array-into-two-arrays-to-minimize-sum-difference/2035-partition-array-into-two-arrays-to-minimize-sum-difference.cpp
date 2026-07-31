class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> leftSums(n + 1), rightSums(n + 1);

        // Generate all subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    bits++;
                }
            }
            leftSums[bits].push_back(sum);
        }

        // Generate all subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, bits = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    bits++;
                }
            }
            rightSums[bits].push_back(sum);
        }

        // Sort right subset sums for binary search
        for (int i = 0; i <= n; i++)
            sort(rightSums[i].begin(), rightSums[i].end());

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            auto &L = leftSums[k];
            auto &R = rightSums[n - k];

            for (int s1 : L) {
                double target = (double)total / 2 - s1;

                auto it = lower_bound(R.begin(), R.end(), target);

                if (it != R.end()) {
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != R.begin()) {
                    --it;
                    int chosen = s1 + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};