class Solution {
public:
    /*int fib(int index){
        if(index==0){
            return 1;
        }
        if(index==1){
            return 0;
        }
        int left=fib(index-1);
        int right=fib(index-2);
        return left+right;*/
    int fib(int index,int n,vector<int>& dp){
            
        if(index==n){
            return 1;
        }
        if(index>n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
            
        dp[index]=fib(index+1,n,dp)+fib(index+2,n,dp);
        return dp[index];
            
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fib(0,n,dp);
        
    }
};