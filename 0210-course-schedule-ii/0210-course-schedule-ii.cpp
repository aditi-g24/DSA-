class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        queue<int> q;
        vector<int> indegree(v,0);
        vector<vector<int>> adj(v);
        vector<int> order;
        vector<int> empty;

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < v; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        for(int i = 0; i < v; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            order.push_back(node);
            q.pop();

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(order.size()==v) {
            return order;
        }

        else return empty;
    }
};