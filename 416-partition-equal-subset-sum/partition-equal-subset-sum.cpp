class Solution {
public:
    bool func(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(target==0){
            return true;
        }
        if(target<0){
            return false;
        }
        if(i == nums.size()){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int take=func(i+1,nums,target-nums[i],dp);
        int skip=func(i+1,nums,target,dp);
        return dp[i][target]=take||skip;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>>dp(n, vector<int>(target + 1,-1));
        return func(0,nums,sum/2,dp);
        
    }
};