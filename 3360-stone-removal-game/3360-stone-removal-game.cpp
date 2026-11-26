class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10){
            return false;
        }
        int cnt = 0;
        int a = 10;
        while(n >= a){
            n = n - a;
            cnt++;
            a--;
        }
        if(cnt % 2 == 0){
            return false;
        }
        return true;
    }
};