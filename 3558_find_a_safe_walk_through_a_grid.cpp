class Solution {
    int m,n;
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool isValid(int r,int c){
        return r>=0 && c>=0 && r<m && c<n;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>> pq;
        if(grid[0][0]==1){
            health--;
        }
        pq.push({health,{0,0}});
        dist[0][0] = health;

        while(!pq.empty()){
            int currHealth = pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(currHealth<dist[x][y]) continue;

            for(auto it:dir){
                int nx=x+it[0];
                int ny=y+it[1];
                if(isValid(nx,ny)){
                    int newHealth;
                    if(grid[nx][ny]==1){
                        newHealth = currHealth-1;
                    }else{
                        newHealth = currHealth;
                    }

                    if(dist[nx][ny]<newHealth){
                        dist[nx][ny] = newHealth;
                        pq.push({newHealth,{nx,ny}});
                    }
                }
            }
        }

        if(dist[m-1][n-1]<=0){
            return false;
        }

        return true;
    }
};