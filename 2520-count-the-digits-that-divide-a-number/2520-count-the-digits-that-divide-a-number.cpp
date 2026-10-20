class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int temp = num;
        while(num > 0){
            if(temp % (num % 10) == 0){
                ans++;
            }
            num = num/10;
        }
        return ans;
    }
};