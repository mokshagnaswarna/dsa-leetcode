/*class Solution {
public:
    void func(int ind,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&curr){
        int n=nums.size();
        if(ind==n){
            
            return;
        }
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target){
                break;
            }
            curr.push_back(nums[i]);
            func(i+1,nums,target-nums[i],ans,curr);
            curr.pop_back();
        }

        
    }
    vector<vector<int>> combinationSum2(vector<int>&nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        func(0,nums,target,ans,curr);
        
        return ans;
    }
};
*/
class Solution {
public:
    void func(int ind, vector<int>& nums, int target,
              vector<vector<int>>& ans, vector<int>& curr) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        for(int i = ind; i < nums.size(); i++) {

            // Skip duplicate values at the same level
            if(i > ind && nums[i] == nums[i - 1])
                continue;

            // Array is sorted
            if(nums[i] > target)
                break;

            // Take
            curr.push_back(nums[i]);

            func(i + 1, nums, target - nums[i],
                 ans, curr);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        func(0, nums, target, ans, curr);

        return ans;
    }
};