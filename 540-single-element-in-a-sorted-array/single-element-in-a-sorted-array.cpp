class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int left=0,right=arr.size()-1;
        int ans=-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(mid%2==1){
                mid--;
            }
            if(arr[mid]==arr[mid+1]){
                left=mid+2;
            }
            else{
                right=mid;
            }
            
        }
        return arr[left];
    }
};