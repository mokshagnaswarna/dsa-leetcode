/*class Solution {
public:
    long long countCommas(long long n) {
        string s=to_string(n);
        if(s.length()<4){
            return 0;
        }

        if(s.length()>=4 && s.length()<=6){
            return n-999;
        }
        return n-999;

    }
};
class Solution {
public:
    int countCommas(int n) {
        string s=to_string(n);
        if(s.length()<4){
            return 0;
        }
        
        if(s.length()>=4){
            int count=0;
            if(s.length()==4){
                count=n-999;
            }
            if(s.length()==5){
                count=9000+(n-9999);
            }
            if(s.length()==6){
                count=9000+(n-9999);
            }
            return count;
        }
        return 0;
        
    }
};


class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;
        if (n >= 1000) {
            ans += n - 999;
        }
        if (n >= 1000000) {
            ans += 2LL * (n - 999999);
        }
        if (n >= 1000000000) {
            ans += 3LL * (n - 999999999);
        }
        return ans;
    }
};*/
class Solution {
public:
    long long countCommas(long long n) {
        long long p = 1000, res = 0;
        while (p <= n){
            res += n - p + 1;
            p *= 1000;
        }
        return res;
    }
};
