class Solution {
public:
    int digSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(i == digSum(nums[i])){
                mini = min(mini, i);
            }
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};