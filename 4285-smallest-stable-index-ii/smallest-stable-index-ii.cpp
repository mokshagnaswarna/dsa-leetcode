/*class Solution {
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
        return j;
        return -1;
    }
};*/ // o(n2)

//o(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minValue(n);
        minValue[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minValue[i] = min(minValue[i + 1], nums[i]);
        }

        int maxValue = 0;
        for (int i = 0; i < n; ++i) {
            maxValue = max(maxValue, nums[i]);
            if (maxValue - minValue[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
