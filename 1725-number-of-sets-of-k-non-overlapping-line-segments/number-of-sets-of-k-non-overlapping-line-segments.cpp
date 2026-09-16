/*class Solution {
public:
    int m=1e9+7;
    int numberOfSets(int n, int k) {
        int dp[1001][1001];
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=k;i++){
            vector<int>prefix(n+1,0);
            for(int l=0;l<n;l++){
               prefix[l+1]=(prefix[l]+dp[i-1][l])%m;
            }
            int take=0;
            for(int j=n-1;j>0;j--){
                take=prefix[j+1];
                int skip=dp[i][j-1];
                dp[i][j]=take+skip;
            }
        }
        return dp[k][0];
    }
};*/
class Solution {
public:
    int m=1e9+7;

    int numberOfSets(int n, int k) {
        int dp[1001][1001] = {};

        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }

        for(int i=1;i<=k;i++){

            vector<int> prefix(n+1,0);

            for(int l=0;l<n;l++){
                prefix[l+1]=(prefix[l]+dp[i-1][l])%m;
            }

            for(int j=1;j<n;j++){
                int take=prefix[j];
                int skip=dp[i][j-1];

                dp[i][j]=(take+skip)%m;
            }
        }

        return dp[k][n-1];
    }
};