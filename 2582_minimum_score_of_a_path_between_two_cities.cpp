class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        queue<int> q;
        vector<bool> visited(n+1,false);
        q.push(1);
        visited[1] = true;
        int miniWt=INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it : adj[node]){
                int neigh = it.first;
                int neighWeight = it.second;
                miniWt =min(miniWt,neighWeight);

                if(!visited[neigh]){
                    visited[neigh]=true;
                    q.push(neigh);
                }
            }
        }

        return miniWt;


    }
};