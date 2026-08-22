class Solution {
public:
    void func(int ind,vector<int>& candidates,vector<vector<int>>&res,int sum,vector<int>&curr){
        int n=candidates.size();
        //base case
        if(ind==n){
            if(sum==0){
                res.push_back(curr);
            }
            return;
        }
        if(candidates[ind]<=sum){
            curr.push_back(candidates[ind]);
            func(ind,candidates,res,sum-candidates[ind],curr);
            curr.pop_back();
            
        }
        func(ind+1,candidates,res,sum,curr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;
        int sum=target;
        func(0,candidates,res,sum,curr);
        return res;
    }
};