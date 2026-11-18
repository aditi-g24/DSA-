class Solution {
public:
    int minChanges(string s) {
        int ans = 0;

        for(int i = 0; i < s.size()-1; i++){
            if(s[i] != s[i+1]){
                ans++;
            }
            i = i + 1;
        }
        return ans;
    }
};