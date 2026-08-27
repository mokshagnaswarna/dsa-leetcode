/*class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n1=nums1.size();
        int n2=nums2.size();
        int count=0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    count=j;
                }
            }
        }
        for(int j=0;j<n2;j++){
            sort(nums2.begin(),nums2.end());
            if(nums2[count]!=nums2[count+1] && count<n2-1){
                ans.push_back(nums2[count+1]);
            }
            if(nums2[count]==nums2[count+1] && count==n2-2){
                ans.push_back(-1);
            }
            if(nums2[count]==nums2[count+1] && count<n2-2){
                if(nums2[count]!=nums2[count+2]){
                    ans.push_back(nums2[count+2]);
                }
                
            }
        }
        return ans;
    }
};*/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            int index = -1;

            // Find nums1[i] in nums2
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    index = j;
                    break;
                }
            }
            int greater = -1;

            for(int j = index + 1; j < nums2.size(); j++) {
                if(nums2[j] > nums1[i]) {
                    greater = nums2[j];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};