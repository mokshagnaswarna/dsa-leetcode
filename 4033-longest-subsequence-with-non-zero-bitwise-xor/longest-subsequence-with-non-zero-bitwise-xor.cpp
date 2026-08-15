class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int resultxor=0;
        bool all=true;
        for(int x:nums){
            resultxor^=x;
            if(x!=0){
                all=false;
            }
        }
        if(all){
            return 0;
        }
        return (resultxor==0)?n-1:n;
        
    }
};