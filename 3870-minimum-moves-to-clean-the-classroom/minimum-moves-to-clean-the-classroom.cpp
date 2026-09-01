class Solution {
public:
    int minMoves(vector<string>&classr, int energy) {
        int m=classr.size();
        int n=classr[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int sx,sy,count=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (classr[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classr[i][j] == 'L') {
                    vis[i][j] = 1 << count++;
                }
            }
        }
        vector<vector<vector<int>>>beste(m,vector<vector<int>>(n,vector<int>(1<<count,-1)));
        struct info{
            int x,y,mask,e,steps;
        };
        queue<info>q;
        q.push({sx,sy,0,energy,0});
        beste[sx][sy][0] = energy;
        while(!q.empty()){
            info t=q.front();
            q.pop();
            if(t.mask==(1<<count) -1){
                return t.steps;
            }
            if(t.e==0){
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = t.x + dx[i];
                int ny = t.y + dy[i];
                if (nx <0|| nx >= m || ny < 0 || ny >= n ||
                    classr[nx][ny] == 'X') {
                    continue;
                }
                int ne = classr[nx][ny] == 'R' ? energy : t.e - 1;
                int nmask = t.mask|vis[nx][ny];
                if(ne>beste[nx][ny][nmask]){
                    beste[nx][ny][nmask]=ne;
                    q.push({nx,ny,nmask,ne,t.steps+1});
                }
            }
        }
        return -1;
    }
};