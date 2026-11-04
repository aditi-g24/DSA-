
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // lower: smaller half, upper: larger half
        multiset<int> lower, upper;

        long long lowerSum = 0;
        long long upperSum = 0;

        // Maintain the two halves
        auto rebalance = [&]() {
            int target = (lower.size() + upper.size() + 1) / 2;

            while ((int)lower.size() > target) {
                int val = *lower.rbegin();

                lower.erase(prev(lower.end()));
                lowerSum -= val;

                upper.insert(val);
                upperSum += val;
            }

            while ((int)lower.size() < target) {
                int val = *upper.begin();

                upper.erase(upper.begin());
                upperSum -= val;

                lower.insert(val);
                lowerSum += val;
            }
        };

        auto add = [&](int val) {
            if (lower.empty() || val <= *lower.rbegin()) {
                lower.insert(val);
                lowerSum += val;
            } else {
                upper.insert(val);
                upperSum += val;
            }

            rebalance();
        };

        auto remove = [&](int val) {
            auto it = lower.find(val);

            if (it != lower.end()) {
                lower.erase(it);
                lowerSum -= val;
            } else {
                it = upper.find(val);
                upper.erase(it);
                upperSum -= val;
            }

            rebalance();
        };

        // Calculate cost of every window of size x
        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *lower.rbegin();

                long long leftCost =
                    median * (long long)lower.size() - lowerSum;

                long long rightCost =
                    upperSum - median * (long long)upper.size();

                cost.push_back(leftCost + rightCost);
            }
        }

        // DP: minimum cost to select j non-overlapping windows
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = n - 1; i >= 0; i--) {
                // Skip index i
                curr[i] = curr[i + 1];

                // Pick window starting at i
                if (i + x <= n && prev[i + x] != INF) {
                    curr[i] = min(
                        curr[i],
                        cost[i] + prev[i + x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[0];
    }
};
