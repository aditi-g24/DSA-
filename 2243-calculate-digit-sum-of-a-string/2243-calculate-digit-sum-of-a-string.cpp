class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string t = "";
            int sum = 0;
            int cnt = 0;
            for(int i = 0; i < s.size(); i++){
                sum += s[i] - '0';
                cnt++;
                if(cnt == k || i == s.size()-1){
                    t += to_string(sum);
                    sum = 0;
                    cnt = 0;
                }
            }
            s = t;
        }
        return s;
    }
};