class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};