class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int left=1;
        int right = *max_element(nums.begin(), nums.end());
        while(left<right){
            int sum=0;
            int mid=left+(right-left)/2;
            for(int i=0;i<n;i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum>threshold){
                left=mid+1;
            }
            else{
                right=mid;
            }

        }
        return left;
        
    }
};