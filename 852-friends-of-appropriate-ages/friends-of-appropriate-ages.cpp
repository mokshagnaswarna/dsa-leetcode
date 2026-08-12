class Solution {
public:
    int numFriendRequests(vector<int>& age) {
        int cnt[121]={};
        int ans=0;
        for(int x:age){
            cnt[x]++;
        }
        for(int i=0;i<121;i++){
            for(int j=0;j<121;j++){
                
                if((j>i/2.0+7 && j<=i) && !(j > 100 && i < 100)){
                        if(i==j){
                            ans+=cnt[i]*(cnt[j]-1);
                        }
                        else{
                            ans+=cnt[i]*cnt[j];
                        }
                    }
                
                
            }
        }
        return ans;
    }
};