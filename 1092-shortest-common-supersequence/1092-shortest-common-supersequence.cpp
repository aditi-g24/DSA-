class Solution {
public:
    int solve(string& str1, string& str2, vector<vector<int>>& dp, int i, int j){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j]){
            return dp[i][j] = 1 + solve(str1, str2, dp, i-1, j-1);
        }

        return dp[i][j] = max(solve(str1, str2, dp, i-1, j), solve(str1, str2, dp, i, j-1));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        int lcs = solve(str1, str2, dp, n-1, m-1);

        int i = n-1;
        int j = m-1;
        string ans = "";
        while(i >= 0 && j >= 0){
            if(str1[i]==str2[j]){
                ans+=str1[i];
                i--;
                j--;
            }
            else if(solve(str1, str2, dp, i-1, j) > solve(str1, str2, dp, i, j-1)){
                ans+=str1[i];
                i--;
            }
            else{
                ans+=str2[j];
                j--;
            }
        }
        while(i >= 0){
            ans+=str1[i--];
        }
        while(j >= 0){
            ans+=str2[j--];
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};