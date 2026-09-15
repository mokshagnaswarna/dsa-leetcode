class Solution {
public:
    bool ispalindrome(string& s,int k,int i,int j){
        int l=s.length();
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;

        }
        return true;
    }
    int solve(string& s,int k,int i,int j,vector<vector<int>>& dp){
        int n=s.length();
        if(i>=n ||j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(ispalindrome(s,k,i,j)){
            int take=1+solve(s,k,j+1,j+k,dp);
            int grow=solve(s,k,i,j+1,dp);
            int slide=solve(s,k,i+1,j+1,dp);
            int q=max(take,grow);
            dp[i][j]=max(q,slide);
        }
        else{
            int grow=solve(s,k,i,j+1,dp);
            int slide=solve(s,k,i+1,j+1,dp);
            dp[i][j]=max(grow,slide);
        }
        return dp[i][j];


        
    }
    int maxPalindromes(string s, int k) {
        int l=s.length();
        vector<vector<int>>dp(l+1,vector<int>(l+1,-1));
        if(l<k){
            return 0;
        }
        if(k==1){
            return l;
        }
        return solve(s,k,0,k-1,dp);

    }
};