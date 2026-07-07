class Solution {
private : 
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid, int dr[], int dc[]){
        vis[row][col] = 1;
        int r = grid.size();
        int c = grid[0].size();

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nr < r && nc >= 0 && nc < c
            && !vis[nr][nc] && grid[nr][nc]==1) {
                dfs(nr, nc, vis, grid, dr, dc);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < n; i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid,dr,dc);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i, m-1, vis, grid, dr, dc);
            }
        }

        for(int j = 0; j < m; j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0, j, vis, grid, dr, dc);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1, j, vis, grid, dr, dc);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }   
    return cnt;
    }
};