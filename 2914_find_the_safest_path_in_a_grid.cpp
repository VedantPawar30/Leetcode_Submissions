class Solution {
    int m;
    int n;
    vector<vector<int>> dir ={{1,0},{-1,0},{0,1},{0,-1}};
public:
    bool isValid(int r,int c){
        return r>=0 && c>=0 && r<m && c<n;
    }

    int manDist(int x1,int y1,int x2,int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> safeScore(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    visited[i][j] =true;
                } 
            }
        }
       
        while(!q.empty()){
            int x = q.front().first.first;
            int y=q.front().first.second;
            int currDist = q.front().second;
            q.pop();

            for(auto it:dir){
                int newX = x+it[0];
                int newY = y+it[1];
                if(isValid(newX,newY) && !visited[newX][newY] && grid[newX][newY]==0){
                    visited[newX][newY] =true;
                    safeScore[newX][newY] = currDist+1;
                    q.push({{newX,newY},currDist+1});
                }
            }
        }



        vector<vector<int>> dist(m,vector<int>(n,0));
        dist[0][0] = safeScore[0][0];
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>> pq;
        pq.push({dist[0][0],{0,0}});

        while(!pq.empty()){
            int currMinSafe = pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(x==m-1 && y==n-1){
                return currMinSafe;
            }

            for(auto it : dir){
                int newX = x+it[0];
                int newY = y+it[1];
                if(isValid(newX,newY)){
                    int newSafeScore = safeScore[newX][newY];
                    int currNeighSafe = min(currMinSafe,newSafeScore);
                    if(dist[newX][newY] < currNeighSafe){
                        dist[newX][newY] = currNeighSafe;
                        pq.push({currNeighSafe,{newX,newY}});
                    }
                }
            }
        }

        return 0;
    }
};