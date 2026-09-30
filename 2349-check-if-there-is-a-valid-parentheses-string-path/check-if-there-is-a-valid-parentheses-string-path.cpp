class Solution {
public:
int t[101][101][201];
    bool solve(vector<vector<char>>& grid,int i,int j,int count){
        int m=grid.size();
        int n=grid[0].size();
        count+=(grid[i][j]=='(')?1:-1;
        if(count<0){
            return false;
        }
        if(t[i][j][count]!=-1){
            return t[i][j][count];
        }
        
        
        
        if(i==m-1 && j==n-1){
            return t[i][j][count]=(count==0);
        }
        if(i+1<m){//down
            if(solve(grid,i+1,j,count)==true){
                return t[i][j][count]=true;
            }
        }
        if(j+1<n){//down
            if(solve(grid,i,j+1,count)==true){
                return t[i][j][count]=true;
            }
        }
        return t[i][j][count]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==')'){
            return false;
        }
        if((m+n-1)%2!=0){
            return false;
        }
        memset(t,-1,sizeof(t));
        return solve(grid,0,0,0);
    }
};