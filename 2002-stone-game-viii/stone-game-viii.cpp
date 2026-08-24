/*class Solution {
public:

    int func(int i, vector<int>& pre,vector<int>&dp) {

        int n = pre.size();

        // Last possible state
        if (i == n - 1) {
            return pre[i];
        }
        if(dp[i]!=INT_MIN){
            return dp[i];
        }

        int ans = INT_MIN;

        for (int j = i; j < n - 1; j++) {

            int take = pre[j] - func(j + 1, pre,dp);
            int skip=func(j+1,pre,dp);
            ans = max(skip, take);
        }
        dp[i]=ans;
        return ans;
    }

    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();

        vector<int> pre(n);

        pre[0] = stones[0];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + stones[i];
        }
        vector<int>dp(n,INT_MIN);

        return func(1, pre,dp);
    }
};*/

class Solution {
public:

    int func(int i, vector<int>& pre, vector<int>& dp) {

        int n = pre.size();

        // Base case
        if (i == n - 1) {
            return pre[i];
        }

        // Already calculated
        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        // Take
        int take = pre[i] - func(i + 1, pre, dp);

        // Skip
        int skip = func(i + 1, pre, dp);

        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();

        // Prefix sum
        vector<int> pre(n);

        pre[0] = stones[0];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + stones[i];
        }

        // DP array
        vector<int> dp(n, INT_MIN);

        return func(1, pre, dp);
    }
};