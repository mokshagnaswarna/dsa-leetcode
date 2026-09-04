class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        /*queue<pair<int,int>>q;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        q.push({0,0});
        int a=INT_MAX ;
        while(!q.empty()){
            int sr=q.front().first;
            int sc=q.front().second;
            for(int i=0;i<4;i++){
                int nx=sr+dx[i];
                int ny=sc+dy[i];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n ){
                    a=min(a,abs(heights[nx][ny]-heights[sr][sc]));
                    if(nx==m-1 && ny==n-1){
                        return a;
                    }
                    q.push({nx,ny});
                }
            }
        }
        return a;*/
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        effort[0][0]=0;
        q.push({{0,0},0});
        while(!q.empty()){
            int sr=q.front().first.first;
            int sc=q.front().first.second;
            int curreffort=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx=sr+dx[i];
                int ny=sc+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n ){
                    int neweffort=max(curreffort,abs(heights[nx][ny]-heights[sr][sc]));
                    if(neweffort<effort[nx][ny]){
                        effort[nx][ny]=neweffort;
                        q.push({{nx,ny},neweffort});
                    }
                }
            }
        }return effort[m-1][n-1];;

    }
};