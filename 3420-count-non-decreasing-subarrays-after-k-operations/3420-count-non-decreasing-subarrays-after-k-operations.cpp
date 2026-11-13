class Solution {
    struct Block {
        int idx;
        long long val;
        long long len;
        long long cum_area;
    };
    
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        
        // Standard prefix sums for the original array elements
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        vector<Block> stack;
        long long ans = 0;
        int R = n - 1;
        
        // Lambda to compute operations needed to make nums[L..curr_R] non-decreasing
        auto get_cost = [&](int L, int curr_R) {
            // Binary search the stack to find the block containing curr_R
            // (Note: stack indices are strictly descending from front to back)
            int low = 0, high = stack.size() - 1;
            int p = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (stack[mid].idx <= curr_R) {
                    p = mid;
                    high = mid - 1; 
                } else {
                    low = mid + 1;
                }
            }
            
            // Subtract the excess area to the right of curr_R
            long long right_end = stack[p].idx + stack[p].len - 1;
            long long count_after = right_end - curr_R;
            long long area_after = count_after * stack[p].val;
            long long area_below = (p > 0) ? stack[p - 1].cum_area : 0;
            
            long long max_sum = stack.back().cum_area - (area_after + area_below);
            long long actual_sum = pref[curr_R + 1] - pref[L];
            
            return max_sum - actual_sum;
        };
        
        for (int L = n - 1; L >= 0; --L) {
            long long val = nums[L];
            long long len = 1;
            
            // Absorb smaller elements to the right into the current maximum block
            while (!stack.empty() && stack.back().val <= val) {
                len += stack.back().len;
                stack.pop_back();
            }
            
            long long cum = (stack.empty() ? 0 : stack.back().cum_area) + val * len;
            stack.push_back({L, val, len, cum});
            
            // Shrink right boundary until the subarray requires <= k operations
            while (R >= L && get_cost(L, R) > k) {
                R--;
            }
            
            // All subarrays starting at L and ending anywhere up to R are valid
            ans += (R - L + 1);
        }
        
        return ans;
    }
};