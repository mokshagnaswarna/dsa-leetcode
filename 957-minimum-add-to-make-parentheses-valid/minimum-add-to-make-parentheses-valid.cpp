class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open+=1;
            }
            if(s[i]==')'){
                if(open==close){
                    open+=1;
                    count++;
                }
                close++;
            }
        }
        if(open>close){
            count+=abs(open-close);
        }
        return count;
    }
};