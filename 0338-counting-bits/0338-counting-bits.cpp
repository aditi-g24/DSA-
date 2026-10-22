class Solution {
public:
    int solve(int i){
        int count = 0;
        while( i != 0){
            count += (i & 1);
            i >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};