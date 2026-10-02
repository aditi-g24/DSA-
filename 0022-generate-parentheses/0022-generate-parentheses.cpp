class Solution {
public:
        string curr;
        vector<string> ans;
        int open = 0;
        int close = 0;

    void solve(string curr, int open, int close, int n){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            solve(curr + '(', open + 1, close, n);
        }

        if(close < open){
            solve(curr + ')', open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n){
        int num = n;
        solve("", 0, 0,num);
        return ans;
    }
};