class Solution {
public:
     int solve(int i,vector<int>& coins,int amount,vector<vector<int>>& t){
        int n=coins.size();
        if(amount==0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(t[i][amount]!=-1){
            return t[i][amount];
        }
        int take=0;
        int skip=solve(i-1,coins,amount,t);
        if(coins[i]<=amount){
            take=solve(i,coins,amount-coins[i],t);
        }
        return t[i][amount]=take+skip;
    }
    int change(int amount,vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>t(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,t);  
    }
};

    
   
    