class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<bool>arr(1000);
        int count=0;
        for(int i=0;i<digits.size();i++){
            if(digits[i]%2==0){
                count++;
            }
        }
        if(count==0){                        //base case
            return 0;
        }
        int count2=0;
        for(int i=0;i<n;i++){
            if(digits[i]==0){
                continue;
            }
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                for(int k=0;k<n;k++){
                    if(k==j ||k==i ||digits[k]%2!=0){
                        continue;
                    }
                    //int x=100*digits[i]+10*digits[j]+digits[k];
                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(!arr[x]){
                        arr[x]=true;
                        count2++;
                    }
                }
            }
        }
        return count2;

        
    }
};