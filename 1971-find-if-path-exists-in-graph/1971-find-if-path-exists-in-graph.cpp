class Solution {
public:
    bool dfs(int n, vector<vector<int>>& adj, int node, int destination, vector<int>& vis){
        if(node == destination){
            return true;
        }
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(n, adj, it, destination,vis)){
                    return true;
                }
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return dfs(n, adj, source, destination,vis);
    }
};