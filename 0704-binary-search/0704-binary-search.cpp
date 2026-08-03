class Solution {
private : 
    int bs(vector<int>& nums, int target, int high, int low){
        if(low > high) return -1;
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]){
            return bs(nums, target, high, mid + 1);
        }
        else return bs(nums, target, mid - 1, low);
    }
public:
    int search(vector<int>& nums, int target) {
        return bs(nums, target, nums.size()-1, 0);
    }
};