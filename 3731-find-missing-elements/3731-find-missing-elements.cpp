class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = nums[0];
        int high = nums[n-1];
        int check = low;
        int i = 1;
        while (check < high) {
            if (i < n && nums[i] == check + 1) {
                check++;
                i++;
            } else {
                ans.push_back(check + 1);
                check++;
            }
        }
        return ans;
    }
};