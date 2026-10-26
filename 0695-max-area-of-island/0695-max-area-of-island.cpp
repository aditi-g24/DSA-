class Solution {
public:
    int maxi = INT_MIN;
    int area = 0;

    int bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        area = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                !vis[nr][nc] && grid[nr][nc] == 1){
                    area++;
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    bfs(i,j,vis,grid);
                    maxi = max(maxi,area);
                }
            }
        }

        return (maxi == INT_MIN) ? 0 : maxi;
    }
};