class Solution {
public:
    string removeOuterParentheses(string s) {
       int n=s.length();
       string curr="";
       int count=0;
       vector<string>ans;
       vector<string>ans2;
       string h="";
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            count++;
            curr.push_back(s[i]);
        }
        if(s[i]==')'){
            count--;
            curr.push_back(s[i]);
        }
        if(count==0){
            ans.push_back(curr);
            curr="";
        }
       }
       for(string k:ans){
            
           
            k.erase(0,1);
            k.erase(k.length()-1,1);
            ans2.push_back(k);
            
        
        
       }
       for(string m:ans2){
        h+=m;
       }
       return h;
    }
};