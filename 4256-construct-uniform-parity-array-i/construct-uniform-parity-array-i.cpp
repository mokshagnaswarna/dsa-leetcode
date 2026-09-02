class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        /*bool same=true;
        //base case
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=nums1[0]%2){
                same=false;
                break;
            }
            
        }
        if(same){
            return same;
        }
        vector<int>nums2(nums1.size());
        int j=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                j=i;
                break;
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                nums2[i]=nums1[i];
            }
            else{
                nums2[i]=nums1[i]-nums1[j];
            }
        }
        bool samee=true;
        
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]%2!=nums2[0]%2){
                samee=false;
                break;
            }
            
        }
        return samee;
        */
        return true;

    }
};