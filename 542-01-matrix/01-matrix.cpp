class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;

                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int sx=q.front().first.first;
            int sy=q.front().first.second;
            int steps=q.front().second;
            dis[sx][sy]=steps;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=sx+dx[i];
                int ny=sy+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]!=1){
                    vis[nx][ny]=1;
                    q.push({{nx,ny},steps+1});
                }
            }
        }
        return dis;
        
    }
};