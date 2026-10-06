class Solution {
public:
    
    int solve(int i,vector<int>& coins,int amount,vector<vector<int>>& t){
       
        int n=coins.size();
        if(amount==0){
            return 0;
        }
        if(i<0){
            return 1e9;
        }
        if(t[i][amount]!=-1){
            return t[i][amount];
        }
        int take=1e9;
        int skip=solve(i-1,coins,amount,t);
        if(coins[i]<=amount){
            take=1+solve(i,coins,amount-coins[i],t);
        }
        return t[i][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>t(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,t);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};