class Solution {
public:
    int func(int index,vector<int>& dp,int start,vector<int>& nums){
        if(index<start){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int take = nums[index] + func(index - 2,dp,start,nums);
        int skip = func(index - 1,dp,start,nums);

        return dp[index] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,-1);
        int case1=func(n-2,dp,0,nums);
        vector<int>dp2(n,-1);
        int case2=func(n-1,dp2,1,nums);
        return max(case1,case2);
    }
};