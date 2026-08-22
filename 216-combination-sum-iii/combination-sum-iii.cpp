class Solution {
public:
    void func(int ind,int k,int target,vector<vector<int>>&ans,vector<int>&curr){
        if(target==0&&curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i=ind;i<=9;i++){
            if(i<=target){
                curr.push_back(i);
                func(i+1,k,target-i,ans,curr);
                curr.pop_back();
            }
            else{
                break;
            }
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int target=n;
        vector<vector<int>>ans;
        vector<int>curr;
        func(1,k,target,ans,curr);
        return ans;

    }
};