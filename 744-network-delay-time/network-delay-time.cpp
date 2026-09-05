class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int src=times[i][0];
            int dest=times[i][1];
            int wt=times[i][2];
            adj[src].push_back({dest,wt});

        }
        vector<int>dist(n+1,INT_MAX);
        queue<pair<int,int>>q;
        dist[k]=0;
        q.push({k,0});
        while(!q.empty()){
            int sr=q.front().first;
            int cost=q.front().second;
            q.pop();
            for(auto it:adj[sr]){
                int nei=it.first;
                int price=it.second;
                if(cost+price<dist[nei]){
                    dist[nei]=cost+price;
                    q.push({nei,dist[nei]});
                }
            }
            
            
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                 return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
            

    }
};