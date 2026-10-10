class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> counts(100001, 0);
        long long sumDiff = 0;
        
        for (int i = 0; i < nums1.size(); ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            counts[diff]++;
            sumDiff += diff;
        }
        
        if (sumDiff <= k) return 0;
        
        for (long long i = 100000; i > 0 && k > 0; --i) {
            if (counts[i] > 0) {
                long long reduce = min(k, counts[i]);
                counts[i] -= reduce;
                counts[i - 1] += reduce;
                k -= reduce;
            }
        }
        
        long long ans = 0;
        for (long long i = 1; i <= 100000; ++i) {
            if (counts[i] > 0) {
                ans += counts[i] * i * i;
            }
        }
        
        return ans;
    }
};