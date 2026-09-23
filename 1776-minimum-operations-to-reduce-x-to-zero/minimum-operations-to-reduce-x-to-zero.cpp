class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        /*vector<int>k(n,0);
        vector<int>l(n,0);
        k[n-1]=nums[n-1];
        l[0]=nums[0];
        for(int i=n-2;i>=0;i--){
            k[i]=k[i+1]+nums[i];
        }
        for(int i=1;i<n;i++){
            l[i]+=l[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(x==k[i]&&x==l[j]){
                    return min(n-i,j);
                }
                if(x==k[i]){
                    return n-i;
                }
                if(x==l[j]){
                    return j;
                }
                
            }
        }*/
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int le=-1;   //len_of_long_subarray
        int left=0;
        
        int d=sum-x;
        if(d < 0){
            return -1;
        }
        int summ=0;
        for(int right=0;right<n;right++){
            summ+=nums[right];
            
            while(summ>d){
                summ-=nums[left];
                left++;
            }
            if(summ==d){
                le=max(le,right-left+1);

            }
        }

        

    
        if(le==-1){
            return -1;
        }
        return n-le;
    }
};