class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>h;
        vector<int>arr;
        int max_count=0;
        int l=0,r=0;
        while(r<n){
            if(h[nums[r]]<k){
                h[nums[r]]++;
                r++;
            }
            else{
                h[nums[l]]--;
                l++;
            }
            
            if(r-l>max_count){
                    max_count=r-l;
            }
                
                
            

        }
        if(r-l>max_count){
                    max_count=r-l;
                }

        return max_count;

        
    }
};