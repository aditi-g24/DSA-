class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<int> ans;

        for (int num : nums) {
            int index = lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin();
            ans.push_back(index);
        }

        return ans;
    }
};