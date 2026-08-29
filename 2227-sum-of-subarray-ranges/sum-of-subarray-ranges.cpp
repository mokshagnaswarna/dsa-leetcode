class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long count=0;
        for(int i=0;i<n;i++){
            int smallest=nums[i];
            int largest=nums[i];
            for(int j=i;j<n;j++){
                smallest=min(smallest,nums[j]);
                largest=max(largest,nums[j]);
                count+=largest-smallest;

            }
        }
        return count;
    }
};