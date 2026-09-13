class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> one1;
        vector<pair<int,int>> one2;

        int n = img1.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j]==1){
                    one1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    one2.push_back({i,j});
                }
            }
        }

        map<pair<int,int>,int> freq;
        int ans = 0;

        for(auto p1 : one1){
            for(auto p2 : one2){
                pair<int,int> shift = {
                    p2.first-p1.first,p2.second-p1.second
                };

                freq[shift]++;
                ans = max(ans, freq[shift]);
            }
        }

        return ans;
    }
};