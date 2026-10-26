class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int low = 0;
        int high = k-1;
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < k; i++){
            sum += arr[i];
        }

        int avg = sum / k;
        if(avg >= threshold){
            ans++;
        }
        high = k;

        while(high < arr.size()){
            sum -= arr[low];
            sum += arr[high];

            avg = sum / k;
            if(avg >= threshold){
                ans++;
            }

            low++;
            high++;
        }

        return ans;
    }
};