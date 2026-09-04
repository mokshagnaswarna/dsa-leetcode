class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //int dx[8]={1,-1,0,0};
        //int dy[8]={0,0,1,-1};
        int dx[8] = {1,-1,0,0,1,1,-1,-1};
        int dy[8] = {0,0,1,-1,1,-1,1,-1};
        if(grid[0][0]==1 ||grid[m-1][n-1]==1){
            return -1;
        }
        if(m == 1 && n == 1)
            return 1;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        dist[0][0]=1;
        q.push({{0,0},1});
        while(!q.empty()){
            int sr=q.front().first.first;
            int sc=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=sr+dx[i];
                int ny=sc+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0 && dis+1<dist[nx][ny]){
                    dist[nx][ny]=dis+1;
                    //q.push({nx,ny},dis+1);
                    if(nx==m-1 && ny==n-1){
                        return dist[nx][ny];
                    }
                    q.push({{nx,ny},dist[nx][ny]});
                }
            }
        }
        
        return -1;
    }
};