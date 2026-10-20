class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int k = 1; k <= n; k++){
            if(n % k == 0){
                bool valid = true;
                int prevMax = INT_MIN;
                for(int start = 0; start < n; start += k){
                    int drop  = 0; 
                    int mini = INT_MAX;
                    int maxi = INT_MIN;
                    for(int j = start; j < start + k; j++){
                        int next = start + (j - start + 1) % k;
                        if(nums[j] > nums[next]){
                            drop++;
                        }
                        mini = min(mini, nums[j]);
                        maxi = max(maxi, nums[j]);
                    } 
                    if(drop > 1 || prevMax > mini){
                        valid = false;
                        break;
                    }
                    prevMax = maxi;
                }
                if(valid){
                    ans += k;
                }
            }
        }
        return ans;
    }
};