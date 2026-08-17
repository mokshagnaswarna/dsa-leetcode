/*class Solution {
public:
    int solve(vector<int>&nums,vector<int>&prefixsum,int l,int r){
        if(l==r){
            return 0;
        }
        int ans=0;
        for(int i=l;i<r;i++){
            long long left_sum=prefixsum[i+1]-prefixsum[l];
            long long right_sum=prefixsum[r+1]-prefixsum[i+1];
        
            if(left_sum<right_sum){
                int score=left_sum+solve(nums,prefixsum,l,i);
                ans=max(ans,score);
            }
            else if(left_sum>right_sum){
                int score=right_sum+solve(nums,prefixsum,i+1,r);
                ans=max(ans,score);
            }
            else{
                long long left_score=left_sum+solve(nums,prefixsum,l,i);
                long long right_score=right_sum+solve(nums,prefixsum,i+1,r);
                int j=max(left_score,right_score);
                ans=max(ans,j);

            }
        }
        return ans;
    }
    int fun(vector<int>&nums){
        int n=nums.size();
        vector<int>prefixsum(n+1,0);
        for(int i=0;i<n;i++){
            prefixsum[i+1]=prefixsum[i]+nums[i];

        }
        return solve(nums,prefixsum,0,n-1);
    }
    int stoneGameV(vector<int>&nums) {
        int alice_score=0;
        int k=nums.size();
        if(k==1){
            return 0;
        }
        alice_score=fun(nums);
        return alice_score;

    }
};
*/
class Solution {
public:
    int solve(vector<int>&nums,vector<int>&prefixsum,vector<vector<int>>&dp,int l,int r){
        if(l==r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=0;
        for(int i=l;i<r;i++){
            long long left_sum=prefixsum[i+1]-prefixsum[l];
            long long right_sum=prefixsum[r+1]-prefixsum[i+1];
        
            if(left_sum<right_sum){
                int score=left_sum+solve(nums,prefixsum,dp,l,i);
                ans=max(ans,score);
            }
            else if(left_sum>right_sum){
                int score=right_sum+solve(nums,prefixsum,dp,i+1,r);
                ans=max(ans,score);
            }
            else{
                long long left_score=left_sum+solve(nums,prefixsum,dp,l,i);
                long long right_score=right_sum+solve(nums,prefixsum,dp,i+1,r);
                int j=max(left_score,right_score);
                ans=max(ans,j);

            }
            dp[l][r]=ans;
        }
        return ans;
    }
    int fun(vector<int>&nums){
        int n=nums.size();
        vector<int>prefixsum(n+1,0);
        for(int i=0;i<n;i++){
            prefixsum[i+1]=prefixsum[i]+nums[i];

        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums,prefixsum,dp,0,n-1);
    }
    int stoneGameV(vector<int>&nums) {
        int alice_score=0;
        int k=nums.size();
        if(k==1){
            return 0;
        }
        alice_score=fun(nums);
        return alice_score;

    }
};

