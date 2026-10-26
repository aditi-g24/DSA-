class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int low = 0;
        int high = k-1;
        int ans = 0;

        for(int i = 0; i < k; i++){
            if(isVowel(s[i])){
                ans++;
            }
        }

        int maxi = ans;
        high = k;

        while(high < s.size()){
            ans -= isVowel(s[low]);
            ans += isVowel(s[high]);

            maxi = max(maxi, ans);
            low++;
            high++;
        }
        return maxi;
    }
};