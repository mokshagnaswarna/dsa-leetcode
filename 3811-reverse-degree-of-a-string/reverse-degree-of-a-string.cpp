class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        /*vector<int>ans;
        for(int i=0;i<26;i++){
            ans.push_back(26-i);
        }
        int sum=0;
       
        for(char c:s){
            int d=c-'a';
            sum+=d*ans[c-1];
        }
        return sum;*/
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=(26-(s[i-1]-'a'))*i;
        }
        return sum;
    }
};