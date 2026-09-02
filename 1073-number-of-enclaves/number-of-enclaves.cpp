class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if((i==0 || i==m-1 || j==0 || j==n-1) &&
                   grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                        
                    }
                    
                }
            }
        }
        while(!q.empty()){
            int sx=q.front().first;
            int sy=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=sx+dx[i];
                int ny=sy+dy[i];
                if(nx>=0 && nx<m && ny >=0 && ny<n && vis[nx][ny]==0 && grid[nx][ny]==1){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                    count++;
            }
        }
        return count;
    }
};