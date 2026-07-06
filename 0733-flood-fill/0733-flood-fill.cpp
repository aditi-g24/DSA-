class Solution {
private: 
    void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>>& ans, int color, int iniColor){
        ans[sr][sc] = color;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m 
            && image[nr][nc] == iniColor && ans[nr][nc]!= color){
                dfs(nr,nc,image,ans,color,iniColor);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr,sc,image,ans,color,iniColor);
        return ans;
    }
};