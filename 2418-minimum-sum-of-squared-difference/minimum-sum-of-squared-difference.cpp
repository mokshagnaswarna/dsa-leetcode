/*class Solution {
public:
    
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k, int k2) {
        int n=nums1.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            if(nums1[i]<nums2[i]){
                
                if(k>=nums2[i]-nums1[i]){
                    nums1[i]=nums1[i]+(nums2[i]-nums1[i]);
                    k-=(nums2[i]-nums1[i]);
                }
                else{
                    nums1[i]+=k;
                    k=0;
                }

            }
            if(nums1[i]>nums2[i]){
                if(k>=nums1[i]-nums2[i]){
                    nums1[i]=nums1[i]-(nums1[i]-nums2[i]);
                    k-=(nums1[i]-nums2[i]);
                }
                else{
                    nums1[i]-=k;
                    k=0;
                }
            }
            if(nums1[i]==nums2[i])continue;

        }
        for(int i=0;i<n;i++){
            if(nums1[i]<nums2[i]){
                
                if(k2>=nums2[i]-nums1[i]){
                    nums2[i]=nums2[i]-(nums2[i]-nums1[i]);
                    k2-=(nums2[i]-nums1[i]);
                }
                else{
                    nums2[i]-=k2;
                    k2=0;
                }

            }
            if(nums1[i]>nums2[i]){
                if(k2>=nums1[i]-nums2[i]){
                    nums2[i]=nums1[i]+(nums1[i]-nums2[i]);
                    k2-=(nums1[i]-nums2[i]);
                }
                else{
                    nums2[i]-=k2;
                    k2=0;
                }
            }
            if(nums1[i]==nums2[i])continue;  
        }
        for(int i=0;i<n;i++){
            sum+=(nums1[i]-nums2[i])*(nums1[i]-nums2[i]);
        }
        return sum;
    }
};*/
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
        }
        if (accumulate(nums1.begin(), nums1.end(), 0LL) <= k) {
            return 0;
        }
        sort(nums1.begin(), nums1.end(), greater<int>());
        nums1.push_back(0);
        for (int i = 1; i <= n; i++) {
            long long cost = (long long)(nums1[i - 1] - nums1[i]) * i;
            if (cost > k) {
                long long q = k / i, r = k % i;
                long long hi = nums1[i - 1] - q;
                long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
                for (int j = i; j < n; j++) {
                    ans += (long long)nums1[j] * nums1[j];
                }
                return ans;
            }
            k -= cost;
        }
        return 0;
    }
};