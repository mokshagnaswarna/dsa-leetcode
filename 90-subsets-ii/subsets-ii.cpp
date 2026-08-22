class Solution {
public:
    void func(int ind,vector<int>&curr,vector<vector<int>>&ans,vector<int>& nums){
        int n=nums.size();
        
        ans.push_back(curr);
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            func(i+1,curr,ans,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        
        vector<int>curr;
        func(0,curr,ans,nums);
        return ans;
    }
};