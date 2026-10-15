class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(tolower(s[right]) == tolower(s[left])){
                right--;
                left++;
            }
            else{
                return false;
            }
        }

        return true;
    }
};