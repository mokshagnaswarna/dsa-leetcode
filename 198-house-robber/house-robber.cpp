class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
       
        if(n == 1)
            return nums[0];

        int prev2=nums[0];
        int prev=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int take=prev2+nums[i];
            int skip=prev;
            int curr=max(take,skip);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};