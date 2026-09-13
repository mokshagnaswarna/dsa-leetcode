class Solution {
public:
    int cp(vector<vector<int>>& img1,vector<vector<int>>& img2,int r,int c){
        int m=img1.size();
        int count=0;
        int n=img1[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int b_r=i+r;
                int b_c=j+c;
                if(b_r<0 || b_r>=m ||b_c<0 ||b_c>=n){
                    continue;
                }
                if(img1[i][j]==1 && img2[b_r][b_c]==1){
                    count++;
                }
            }
        }
        return count;
        
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int m=img1.size();
        int n=img1[0].size();
        
        int countn=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    countn++;
                }
            }
        }
        if(countn==0){
            return 0;
        }
        int count2=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(img2[i][j]==1){
                    count2++;
                }
            }
        }
        if(count2==0){
            return 0;
        }
        int maxoverlap=0;
        int count=0;
        for(int r=-n+1;r<=n-1;r++){
            for(int c=-n+1;c<=n-1;c++){
                count=cp(img1,img2,r,c);
                maxoverlap=max(maxoverlap,count);

            }
        }
        return maxoverlap;
        



    }

};