class Solution {
public:
    int singleNonDuplicate(vector<int>&arr) {
        int n=arr.size();
        int ans=arr[n-1];
        for(int i=0;i<n-1;i++){
            if(i!=0){
                if(arr[i-1] < arr[i] && arr[i] < arr[i+1]){
                    ans=arr[i];
                    break;
                }
                
            }
            else{
               if(arr[i] < arr[i+1]){
                ans=arr[i];
                
               }
            }
            
        }
        return ans;
    }
};