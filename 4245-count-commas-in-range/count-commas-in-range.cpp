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