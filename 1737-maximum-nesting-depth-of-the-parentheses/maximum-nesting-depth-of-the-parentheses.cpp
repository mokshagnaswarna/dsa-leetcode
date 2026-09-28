class Solution {
public:
    int maxDepth(string s) {
        int l=0;
        int r=0;
        int n=s.length();
 
        int count=0;
        int ans=0;
       
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                    
                    count++;
                    ans=max(ans,count);
                }
                if(s[i]==')'){

                    count--;
                }
            }
        
        return ans;
    }
};