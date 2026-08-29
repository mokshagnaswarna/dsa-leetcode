class Solution {
public:
    vector<int> asteroidCollision(vector<int>&nums) {
        int n=nums.size();
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                s.push(nums[i]);
            }
            else{
                bool destroyed=false;
                while(!s.empty() && s.top()>0 && s.top()<abs(nums[i])){
                    s.pop();
                    
                }
                if(!s.empty()&& s.top()>0 && s.top()==abs(nums[i])){
                    s.pop();
                    destroyed=true;
                }
                if(!destroyed && (s.empty()||s.top()<0)){
                    s.push(nums[i]);
                }
            }
            
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
            
    }
};