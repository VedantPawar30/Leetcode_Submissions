class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cnt=0;
        vector<bool> visited(n,false);
        for(int v=0;v<n;v++){
            if(!visited[v]){
                queue<int> q;
                q.push(v);
                visited[v] = true;
                int cntV=0;
                int cntE=0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    cntV++;
                    cntE += adj[node].size();
                    for(auto &neigh:adj[node]){
                        if(!visited[neigh]){
                            q.push(neigh);
                            visited[neigh] =true;
                        } 
                    }
                }
                cntE /= 2;
                int expEdges = cntV*(cntV-1)/2;
                if(expEdges==cntE) cnt++;
            }

            
        }

        return cnt;
    }
};