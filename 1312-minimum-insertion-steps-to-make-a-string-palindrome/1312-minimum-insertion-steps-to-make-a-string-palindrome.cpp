class Solution {
public:
    int solve(string& s,string& t,int i, int j, vector<vector<int>>& dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1)  return dp[i][j];

        if(s[i] == t[j]){
            return dp[i][j] = 1 + solve(s,t,i-1,j-1,dp);
        }
        return dp[i][j] = max(solve(s,t,i-1,j,dp), solve(s,t,i,j-1,dp));
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int lps = solve(s, t,n-1,n-1, dp);
        
        return n-lps;
    }
};