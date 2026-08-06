class Solution {
public:
    int d(int p){
        int pr=1;
        while(p!=0){
            pr*=p%10;
            p/=10;
        }
        return pr;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(d(n)%t==0){
                return n;
            }
            n++;
        }   
    }
};