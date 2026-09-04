class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>indegree(graph.size());
        vector<vector<int>>adj(n);
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
                
            }
        }
        for(int i = 0; i < n; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }


        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(auto it:adj[u]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;

    }
};