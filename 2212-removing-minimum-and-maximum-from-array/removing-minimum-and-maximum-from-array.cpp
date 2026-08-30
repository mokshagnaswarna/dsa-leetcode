/*class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n=nums.size();
       int l=*max_element(nums.begin(),nums.end());
       int m=*min_element(nums.begin(),nums.end());
       int p=0;
       int k=0;
       int count1=0,count2=0;
       for(int i=0;i<n;i++){
        if(nums[i]==l){
            p=i;
        }
        if(nums[i]==m){
            k=i;
        }
       }
       if(k<n/2){
        count1=k+1;
        }
        else{
            count1=n-k;
        }
       }

        if(p<n/2){
            count2=p+1;
        }
        if(p>n/2){
            count2=n-p;
        }
       }
       return min(count1+count2,min(max(k,p)+1,n-min(k,p)));

    }
};
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());
        int m = *min_element(nums.begin(), nums.end());

        int p = 0;
        int k = 0;

        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == l) {
                p = i;
            }

            if (nums[i] == m) {
                k = i;
            }
        }

        if (k < n / 2) {
            count1 = k + 1;
        }
        else {
            count1 = n - k;
        }

        if (p < n / 2) {
            count2 = p + 1;
        }
        else {
            count2 = n - p;
        }

        return min(count1 + count2,
                   min(max(k, p) + 1,
                       n - min(k, p)));
    }
};