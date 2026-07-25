class Solution {
public:
    int maxProduct(int n) {
        int first=0;
        int sec=0;
        while(n>0){
            int x=n%10;
            if(x>first){
                sec=first;
                first=x;
            }
            else if(x>sec){
                sec=x;
            }
            n=n/10;
        }
        return first*sec;
    }
};