class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = nums[i] + prefix[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};