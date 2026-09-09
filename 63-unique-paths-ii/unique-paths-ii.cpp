class Solution {
public:
    int func(int i,int j,vector<vector<int>>& dp,vector<vector<int>>&grid){
        if(i<0 ||j<0)return 0;
        if(grid[i][j]==1){
            return 0;
        }

        if(i==0 && j==0)return 1;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up=func(i-1,j,dp,grid);
        int left=func(i,j-1,dp,grid);
        dp[i][j]=up+left;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp,grid);
    }
};