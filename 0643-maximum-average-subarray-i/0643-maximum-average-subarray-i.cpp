class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        int low = 0;
        int high = k-1;
        double sum = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        
        avg = sum/k;
        high = k;

        while(high < nums.size()){
            sum -= nums[low];
            sum += nums[high];

            avg = max(avg, sum/k);
            low++;
            high++;
        }

        return avg;
    }
};