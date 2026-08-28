class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left[n];
        int right[n];
        int count=0;
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            count+=min(left[i],right[i])-height[i];
        }
        return count;

    }                                   
};


/*
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int count=0;
        int leftmax=0,rightmax=0;
        while(left<right){
            if(h[left]<=h[right]){
                if(h[left]>=leftmax){
                    leftmax=h[left];
                }
                else{
                    count+=leftmax-h[left];
                }
            }
            else{

            }
        }
    }
};
*/