class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> &ans,int iniColor){
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc]!=color && image[nr][nc]==iniColor){
                dfs(image,nr,nc,color,ans,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        
        int iniColor = image[sr][sc];
        dfs(image,sr,sc,color,ans,iniColor);

        return ans;
    }
};