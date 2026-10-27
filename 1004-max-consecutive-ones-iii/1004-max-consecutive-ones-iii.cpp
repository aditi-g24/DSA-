class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int cnt = 0;
        int ans = INT_MIN;

        while(high < nums.size()){
            if(nums[high] == 1){
                cnt++;
                ans = max(ans, cnt);
                high++;
            }
            else{
                if(k > 0){
                    cnt++;
                    ans = max(ans, cnt);
                    k--;
                    high++;
                }
                else{
                    if(nums[low] == 0){
                        k++;
                        cnt--;
                        low++;
                    }
                    else{
                        cnt--;
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};