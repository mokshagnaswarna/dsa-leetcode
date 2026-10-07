class Solution {
public:
    unordered_set<string>st;
    int maxlen;
    void solve(int i,string& s,unordered_set<string>& st,string& curr,int count){
        int n=s.length();
        if(count<0)return;
        if(i==n){
            if(count==0){
                if(curr.length()>maxlen){
                    maxlen=curr.length();
                    st.clear();
                }
                if(curr.length()==maxlen){
                    st.insert(curr);
                }
                
            }
            return;
        }
        if(s[i]!='(' && s[i]!=')'){
                curr.push_back(s[i]);
                solve(i+1,s,st,curr,count);
                curr.pop_back();
                return;
        }
        curr.push_back(s[i]);
            //solve(i+1,s,st,curr,count+(s[i]=='('?1:-1));
        if (s[i] == '(') {
            solve(i + 1, s, st, curr, count + 1);
        } else {
            solve(i + 1, s, st, curr, count - 1);
        }
        curr.pop_back();
        solve(i+1,s,st,curr,count);
            
        
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        maxlen=0;
        string curr="";
        solve(0,s,st,curr,0);
        vector<string>v(st.begin(),st.end());
        return v;
    }
};