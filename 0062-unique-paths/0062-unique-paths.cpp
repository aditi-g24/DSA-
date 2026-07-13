class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int r = min(m - 1, n - 1);
        for (int i = 1; i <= r; i++) {
            ans = ans * (m + n - 2 - r + i) / i;
        }
        return (int)ans;
    }
};
