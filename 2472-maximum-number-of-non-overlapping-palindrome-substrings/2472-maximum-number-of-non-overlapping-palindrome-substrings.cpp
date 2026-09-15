class Solution {
public:
    string str;
    int n;
    int K;
    vector<int> dp;
    vector<vector<int>> pal;

    bool isPal(int i, int j){
        if(i >= j) return true;
        if(pal[i][j] != -1) return pal[i][j];

        if(str[i] != str[j]){
            return false;
        }

        return pal[i][j] = isPal(i+1,j-1);
    }

    int solve(int i){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int best = solve(i+1);

        for(int j = i; j < n; j++){
            if(j-i+1 >= K && isPal(i,j)){
                best = max(best, 1 + solve(j+1));
            }
        }

        return dp[i] = best;
    }

    int maxPalindromes(string s, int k) {
        str = s;
        K = k;
        n = s.length();

        dp = vector<int>(n + 1, -1);
        pal = vector<vector<int>>(n,vector<int>(n,-1));

        return solve(0);
    }
};