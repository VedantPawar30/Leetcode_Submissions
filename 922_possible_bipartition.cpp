class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n+1);
        for(auto &edge : dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    int nodeClr = color[node];

                    for(auto &neigh : graph[node]){
                        if(color[neigh]==-1){
                            if(nodeClr==0){
                                color[neigh] =1;
                            }else{
                                color[neigh]=0;
                            }
                            q.push(neigh);
                        }
                        else{
                            int neighClr = color[neigh];
                            if(neighClr==nodeClr) return false;
                        }
                    }
                }
                
            }
        }

        return true;
    }
};