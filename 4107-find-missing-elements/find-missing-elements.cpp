class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int n=nums.size();
       vector<int>a;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n-1;i++){
        for(int j=nums[i]+1;j<nums[i+1];j++){
            a.push_back(j);
        }
       }
        
        

        
        
        
       
       return a;
       
    }
};