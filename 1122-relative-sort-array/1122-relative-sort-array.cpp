class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(),arr1.end());

        vector<int> freq(maxi+1,0);
        for(int x : arr1){
            freq[x]++;
        }
        
        int idx = 0;
        for(int i = 0; i < arr2.size(); i++){
            while(freq[arr2[i]] > 0){
                arr1[idx++] = arr2[i];
                freq[arr2[i]]--; 
            }
        }

        for(int i = 0; i <= maxi; i++){
            while(freq[i] > 0){
                arr1[idx++] = i;
                freq[i]--;
            }
        }

        return arr1;
    }
};