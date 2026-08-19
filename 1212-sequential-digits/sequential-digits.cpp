class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789"; 
        vector<int>ans;
        int low_l=to_string(low).size();
        int high_l=to_string(high).size();
        for(int i=low_l;i<=high_l;i++){
            for(int j=0;j+i<=9;j++){
                string k=s.substr(j,i);
                int num=stoi(k);
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;
        
        
        

        
        

    }
};