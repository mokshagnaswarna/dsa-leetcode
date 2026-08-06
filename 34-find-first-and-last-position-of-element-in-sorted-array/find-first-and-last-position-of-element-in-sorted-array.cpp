class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int minn=-1,maxx=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target){
                right=mid-1;
               
                if(nums[mid]==target){
                    minn=mid;
                }
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            
        }
        int leftt=0,rightt=nums.size()-1;
        while(leftt<=rightt){
            int midd=leftt+(rightt-leftt)/2;
            if(nums[midd]>=target){
                
               
                if(nums[midd]==target){
                    maxx=midd;
                    leftt=midd+1;
                }
                else{
                    rightt=midd-1;
                }
            }
            else if(nums[midd]<target){
                leftt=midd+1;
            }
            
        }
        return {minn,maxx};

        
        
    }
};