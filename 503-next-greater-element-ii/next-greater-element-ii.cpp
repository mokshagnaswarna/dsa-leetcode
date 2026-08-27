/*class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        stack<int>s;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(i<n-1){
                s.push(nums[i+1]);
            }
            if(i==n-1){
                for(int j=0;j<i;j++){
                    s.push(nums[j]);
                }
            }
            while(!s.empty()){
            st.push(s.top());
            s.pop();
            }
           
            bool found=false;
            while(!st.empty()){
                if(nums[i]<st.top()){
                    ans.push_back(st.top());
                    found=true;
                    break;
                }
                if(nums[i]>=st.top()){
                    st.pop();
                }
            }
            if(!found){
                ans.push_back(-1);
            }
            
            
            
        }
        return ans;
        
        

    }
};
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr = nums;

        // Double the array
        for(int i = 0; i < n; i++) {
            arr.push_back(nums[i]);
        }

        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse doubled array from right to left
        for(int i = 2*n - 1; i >= 0; i--) {

            // Remove elements that are not greater
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // We only need answers for the first n elements
            if(i < n && !st.empty()) {
                ans[i] = st.top();
            }

            st.push(arr[i]);
        }

        return ans;
    }
};