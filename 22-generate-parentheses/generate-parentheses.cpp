class Solution {
public:
    void func(string curr,vector<string>&ans,int open,int close,int n){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;

        }
        if(open<n){
            func(curr+'(',ans,open+1,close,n);
        }
        if(close<open){
            func(curr+')',ans,open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        func("",ans,0,0,n);
        return ans;
    }
};