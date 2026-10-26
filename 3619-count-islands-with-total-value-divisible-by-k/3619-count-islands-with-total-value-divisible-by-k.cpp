class Solution {
public:
    bool bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int k){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        long long sum = grid[row][col];
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >=0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] && grid[nr][nc] > 0){
                    sum += grid[nr][nc];
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return (sum % k == 0);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] > 0){
                    if(bfs(i,j,vis,grid,k)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};