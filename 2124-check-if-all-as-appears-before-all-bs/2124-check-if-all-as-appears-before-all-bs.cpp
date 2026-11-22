class Solution {
public:
    bool checkString(string s) {
        int b = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b'){
                b++;
            }
            else{
                if(s[i] == 'a' && b != 0){
                    return false;
                }
            }
        }
        return true;
    }
};