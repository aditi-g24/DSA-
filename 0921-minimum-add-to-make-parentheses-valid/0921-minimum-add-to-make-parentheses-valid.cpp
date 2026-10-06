class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
            }
            if(ch == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
        }
        return ans += st.size();
    }
};