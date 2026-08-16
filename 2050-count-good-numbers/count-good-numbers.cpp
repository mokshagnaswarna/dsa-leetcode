class Solution {
public:
    long long pow(long long a,long long b){
        long long ans=1;
        long long mod=1e9+7;
        while(b>0){
            if(b%2==1){
                ans=(ans*a)%mod;

            }
            a=(a*a)%mod;
            b=b/2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long mod=1e9+7;
        long long even=(n+1)/2;
        long long odd=n/2;
        return (pow(5,even)*pow(4,odd))%mod;
        

        

    }
};