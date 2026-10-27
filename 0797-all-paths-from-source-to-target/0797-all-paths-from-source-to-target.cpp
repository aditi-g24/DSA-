class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int node, vector<vector<int>>& graph){
        path.push_back(node);

        if(path.back() == graph.size() - 1){
            ans.push_back(path);
        }
        else{
            for(int i = 0; i < graph[node].size(); i++){
                dfs(graph[node][i], graph);
            }
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0,graph);
        return ans;
    }
};