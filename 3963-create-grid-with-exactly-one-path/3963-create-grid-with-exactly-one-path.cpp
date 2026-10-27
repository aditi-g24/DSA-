class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int j = 0;
        while (j < n) {
            grid[0][j] = '.';
            j++;
        }

        int i = 0;
        while (i < m) {
            grid[i][n - 1] = '.';
            i++;
        }

        return grid;
    }
};