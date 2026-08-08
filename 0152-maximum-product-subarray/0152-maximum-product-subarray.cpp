class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            int tempMax = max({curr, curr * maxi, curr * mini});
            int tempMin = min({curr, curr * maxi, curr * mini});

            maxi = tempMax;
            mini = tempMin;

            ans = max(maxi, ans);
        }
        return ans;

    }
};