class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int left = i + 1;
            int right = n - i;
            int evenleft = (left + 1)/2;
            int evenright = (right + 1)/2;
            int oddleft = left/2;
            int oddright = right/2;
            int count = (evenleft * evenright) + (oddleft * oddright);
            ans += arr[i] * count;
        }
        return ans;
    }
};