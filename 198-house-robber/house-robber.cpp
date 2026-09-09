class Solution {
public:
    int func(int index,vector<int>& nums,int n,vector<int>& dp){
        //base case
        
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int left=nums[index]+func(index-2,nums,n,dp);
        int right=func(index-1,nums,n,dp);
        return dp[index]=max(left,right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return func(n-1,nums,n,dp);
    }
};