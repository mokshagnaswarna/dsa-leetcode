class Solution {
public:
    bool func(vector<int>& bloom, int m, int k,int fix){
        int l=0;
        int r=0;
        while(r<bloom.size()){
            if(bloom[r]>fix){
                l=r+1;
                r++;
            }
            else{
                if(r-l+1==k){
                    m--;
                    if(m==0)return true;
                    r++;
                    l=r;
                    continue;
                }
                r++;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int n=bloom.size();
        long long lll=(long long)m*k;
        if(lll>n){
            return -1;
        }
        int left=1,right=*max_element(bloom.begin(),bloom.end());
        while(left<right){
            int mid=left+(right-left)/2;
            if(func(bloom,m,k,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }

        }
        return left;
        
    }
};