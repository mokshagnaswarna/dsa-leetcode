/*class Solution {
public:
    int solve(int i,vector<int>& arr,vector<int>& curr,vector<vector<int>>& ans,int target){
        int n=arr.size();
        if(i>=n){
            return 0;
        }
        int sum=0;
        if(target==0){
            ans.push_back(curr);
        }

        curr.push_back(arr[i]);
        int take=solve(i,arr,curr,ans,target-arr[i]);
        curr.pop_back();
        int skip=solve(i+1,arr,curr,ans,target-arr[i]);
        return skip+take;
        
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum<target){
            return -1;
        }
        vector<int>curr;
        vector<vector<int>>ans;
        solve(0,arr,curr,ans,target);
        unordered_map<int,int>f;
        for(int i=0;i<ans.size();i++){
            f.insert({ans[i],ans[i].size()});

        }
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        }
        return v[0].second+v[1].second;

    }
};*/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
         int ans = n + 1;
        int s = 0;
        vector<int> dp(n + 1, n);
        for (int l = 0, r = 0; r < n; r++) {
            s += arr[r];
            while (s > target) {
                s -= arr[l++];
            }
            dp[r + 1] = dp[r];
            if (s == target) {
                ans = min(ans, r - l + 1 + dp[l]);
                dp[r + 1] = min(dp[r], r - l + 1);
            }
        }
        return ans == n + 1 ? -1 : ans;

    }
};//not done proprly