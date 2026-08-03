class Solution {
private:
    void bfs(int node, vector<vector<int>> &adjLs, vector<int> &vis){
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adjLs[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0);
        int count = 0;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                count++;
                bfs(i, adjLs, vis);
            }
        }

        return count;
    }
};