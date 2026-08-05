class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &edge : invocations){
            adj[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        q.push(k);
        vector<bool> visited(n,false);
        vector<bool> isSus(n,false);
        visited[k]=true;
        isSus[k]=true;

        while(!q.empty()){
            int node =q.front();
            q.pop();

            for(auto &neigh : adj[node]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh]=true;
                    isSus[neigh] = true;
                }
            }
        }
        bool ans =true;
        for(int i=0;i<n;i++){
            if(!isSus[i]){
                for(auto &neigh : adj[i]){
                    if(isSus[neigh]) ans = false;
                }
            }
        }
        vector<int> res;
        if(!ans){
            for(int i=0;i<n;i++){
                res.push_back(i);
            }
            return res;
        }

        for(int i=0;i<n;i++){
            if(!isSus[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};