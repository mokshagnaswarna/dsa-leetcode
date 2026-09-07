class Solution {
public:
    int MOD=1e9+7;
    int distinctSubseqII(string s) {
        int end[26]={};
        int total=0;
        for(char ch:s){
            int index=ch-'a';
            int oldtotal=total;
            int newsubsequence=(oldtotal+1-end[index]+MOD)%MOD;
            total=(total+newsubsequence)%MOD;
            end[index]=(end[index]+newsubsequence)%MOD;
        }
        return total;
    }
};