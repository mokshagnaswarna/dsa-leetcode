class Solution {
public:
    int findCircleNum(vector<vector<int>>&nums) {
        int m=nums.size();
        int n=nums[0].size();
        vector<int> vis(n, 0);
        queue<int>q;
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
                while(q.size()>0){
                    int u=q.front();
                    q.pop();
                   
                    for(int j=0;j<n;j++){
                        if(nums[u][j] && !vis[j]){
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
                count++;
            }
        }
        return count;
        
    }
};