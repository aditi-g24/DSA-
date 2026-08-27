class Solution {
public:
    vector<int> generateRow(int numRows){
        vector<int> row;
        long long ans = 1;
        int n = numRows;
        row.push_back(1);
        for(int i = 1; i < numRows; i++){
            ans = ans * (n - i);
            ans = ans/i;
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> lis;
        for(int i = 1; i <= numRows; i++){
            lis.push_back(generateRow(i));
        }
        return lis;
    }
};