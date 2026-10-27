class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for (char ch : t) {
            mp[ch]++;
        }

        int low = 0;
        int high = 0;
        int count = t.size();
        int start = 0;
        int minLen = INT_MAX;

        while (high < s.size()) {
            if (mp[s[high]] > 0) {
                count--;
            }
            mp[s[high]]--;

            while (count == 0) {
                if (high - low + 1 < minLen) {
                    minLen = high - low + 1;
                    start = low;
                }

                mp[s[low]]++;
                if (mp[s[low]] > 0) {
                    count++;
                }

                low++;
            }

            high++;
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};