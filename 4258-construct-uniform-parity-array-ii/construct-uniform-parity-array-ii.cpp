class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>nums2(n);
        vector<int>ans;
        
        bool same=true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=nums1[0]%2){
                same=false;
                break;
            }
        }
        if(same){
            return same;
        }
        
        int j = -1;
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 != 0){
                if(j == -1 || nums1[i] < nums1[j]){
                    j = i;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0){
                nums2[i]=nums1[i];
            }
            else{
                if(nums1[i]-nums1[j]>=1 && j!=i){
                    nums2[i]=nums1[i]-nums1[j];
                }
                else if (j == -1 ||nums1[i] <= nums1[j]) {
                    return false;
                }
                
            }
        }
        bool samee=true;
        for(int i=0;i<n;i++){
            if(nums2[i]%2==0){
                samee=false;
                break;
            }
        }
        return samee;

    }
};