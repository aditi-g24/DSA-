class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes(gain.size()+1,0);
        int maxi = 0;
        for(int i = 0; i < gain.size(); i++){
            altitudes[i+1] = gain[i] + altitudes[i];
            maxi = max(maxi,altitudes[i+1]);
        }
        return maxi;

    }
};