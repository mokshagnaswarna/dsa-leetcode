class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char>s;
        string res="";
        for(int i=0;i<n;i++){
            while(!s.empty() && k>0 && s.top()-'0'>num[i]-'0'){
                s.pop();
                k=k-1;
            }
            s.push(num[i]);
            
            
        }
        while(k>0){
            s.pop();
            k--;
        }
        if(s.empty()){
            return "0";
        }
        
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.length()&&res[i]=='0'){
            i++;
        }
        res=res.substr(i);
        if(res==""){
            return "0";
        }
        return res;
    }
};