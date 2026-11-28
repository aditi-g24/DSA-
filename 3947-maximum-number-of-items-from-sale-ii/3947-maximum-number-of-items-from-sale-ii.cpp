class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        int maxFactor = 0;

        for (auto &item : items) {
            maxFactor = max(maxFactor, item[0]);
        }

        // Step 1: Frequency of every factor
        vector<int> freq(maxFactor + 1, 0);

        for (auto &item : items) {
            freq[item[0]]++;
        }

        // Step 2: Calculate free-item opportunities
        vector<int> gain(maxFactor + 1, 0);

        for (int f = 1; f <= maxFactor; f++) {

            int total = 0;

            for (int j = f; j <= maxFactor; j += f) {
                total += freq[j];
            }

            gain[f] = total - 1;
        }

        // Step 3: Find cheapest item
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long minPrice = items[0][1];
        long long ans = 0;
        long long remaining = budget;

        // Step 4: Greedily buy bonus items
        for (auto &item : items) {

            int factor = item[0];
            long long price = item[1];

            // Bonus purchase isn't better than normal purchase
            if (price > 2 * minPrice) {
                break;
            }

            // Maximum bonus copies we can purchase
            long long take = min(
                (long long)gain[factor],
                remaining / price
            );

            ans += 2 * take;
            remaining -= take * price;
        }

        // Step 5: Spend leftover budget on cheapest item
        ans += remaining / minPrice;

        return (int)ans;
    }
};