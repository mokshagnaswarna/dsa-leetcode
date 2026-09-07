class Solution {
public:
    int time=1;
    void dfs(int u,int parent,vector<vector<int>>& bridge,vector<vector<int>>& ans,int n,vector<int>& vis,vector<int>& dt,vector<int>& low){
        vis[u]=1;
        dt[u]=low[u]=time;
        time++;
        for(auto v:ans[u]){
            if(v==parent)continue;
            if(!vis[v]){
                dfs(v,u,bridge,ans,n,vis,dt,low);
                low[u]=min(low[u],low[v]);
                if(low[v]>dt[u]){
                    bridge.push_back({u,v});
                }
            }
            else if(v!=parent){
                low[u]=min(low[u],dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //vector<int>ans;
        vector<vector<int>> ans(n);
        for(auto it:connections){
            ans[it[0]].push_back(it[1]);
            ans[it[1]].push_back(it[0]);

        }
        vector<int> dt(n);
        vector<int> low(n);
        vector<int>vis(n,0);
        vector<vector<int>>bridge;
        dfs(0,-1,bridge,ans,n,vis,dt,low);
        return bridge;
    }
};