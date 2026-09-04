class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>instability(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int m=*max_element(nums.begin(),nums.begin()+i+1);
            int n=*min_element(nums.begin()+i,nums.end());
            instability[i]=m-n;
        }
        //int t=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(instability[i]<=k){
                return i;
                //t=min(t,instability[i]);
                
            }
            
        }
        /*int j=0;
        for(int i=0;i<nums.size();i++){
            if(instability[i]==t){
                j=i;
                break;
            }
        }
        if(t==INT_MAX){
            return -1;
        }
        return j;*/
        return -1;
    }
};