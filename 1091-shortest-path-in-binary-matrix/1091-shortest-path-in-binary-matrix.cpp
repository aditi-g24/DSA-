class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        if(n == 1 && m == 1) return 1;
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dis(n, vector<int>(m,1e9));
        q.push({1,{0,0}});
        dis[0][0] = 1;
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            for(int i = 0; i < 8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m 
                && grid[nr][nc]==0 && dist + 1 < dis[nr][nc]){
                    dis[nr][nc] = dist + 1;
                    if(nr == n-1 && nc == m-1) return dis[nr][nc];
                    q.push({dist + 1, {nr,nc}});
                }
            }
        }
        return -1;
    }
};