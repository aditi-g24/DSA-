class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        vector<int> v = nums;

        for(int i : nums){
            v.push_back(i);
        }

        int count = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] < v[i-1]){
                count = 1;
            }
            else{
                count++;
                if(count == n){
                    return i + 1 - n;
                }
            }
        }

        count = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] > v[i-1]){
                count = 1;
            }
            else{
                count++;
                if(count == n){
                    return i + 2 - n;
                }
            }
        }

        return 1e9;
    }
    int minOperations(vector<int>& nums) {
        int ans = solve(nums);

        if(nums.size() == 1) return 0;

        reverse(nums.begin(),nums.end());

        ans = min(ans, solve(nums) + 1);

        return ans==1e9? -1 : ans;
    }
};