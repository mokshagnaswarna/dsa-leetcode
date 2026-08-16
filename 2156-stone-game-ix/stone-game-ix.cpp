class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        int count0=0,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(stones[i]%3==0){
                count0++;
            }
            else if(stones[i]%3==1){
                count1++;
            }
            else{
                count2++;
            }
        }
        if(count0%2==0 &&(count1>0 && count2>0)){
            return true;
        }
        else if(count0%2==1){
            if(abs(count1-count2)>2){
                return true;
            }
        }
        
        return false;
    }
};