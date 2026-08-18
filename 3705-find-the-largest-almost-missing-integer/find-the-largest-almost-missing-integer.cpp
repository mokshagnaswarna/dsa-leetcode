class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();

        vector<vector<int>>ans;
        unordered_map<int,int>freq;
        vector<int>arr;
        int l=0,r=k-1;
        while(r<n){
            ans.push_back(vector<int>(nums.begin()+l,nums.begin()+r+1));
            l++;
            r++;
        }
        for(int i=0;i<n-k+1;i++){
            set<int>s;
            for(int j=0;j<k;j++){
                s.insert(ans[i][j]);
            }
            for(int i:s){
                freq[i]++;
            }
        }
        for(auto i:freq){
            if(i.second==1){
                arr.push_back(i.first);
            }
        }
        /*if(arr.size()!=0){
            return *max_element(arr.begin(),arr.end());
        }
        if(arr.size()==0 && k!=1){
            return 0;
        }
        
        return -1;
        */
        if(!arr.empty()) {
            return *max_element(arr.begin(), arr.end());
        }

        

        return -1;
        

    }
};