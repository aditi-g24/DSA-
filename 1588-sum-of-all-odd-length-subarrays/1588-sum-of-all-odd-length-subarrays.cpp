class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(arr.size()+1, 0);

        for(int i = 0; i < n; i++){
            prefixSum[i+1] = prefixSum[i] + arr[i];
        }

        int ans = 0;

        for(int left = 0; left < n; left++){
            for(int right = left; right < n; right+=2){
                ans = ans + prefixSum[right + 1] - prefixSum[left];
            }
        }

        return ans;
    }
};