class Solution {
public:
    bool chec(vector<int>& weights, int days,int capacity){
        int r=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                r+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return r<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int left=*max_element(weights.begin(),weights.end());
        int right=0;
        for(int i=0;i<n;i++){
            right+=weights[i];
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(chec(weights,days,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
            
            
        }
        return left;
    }
};