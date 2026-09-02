/*class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        int n=graph[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<int>color(n,-1);
        color[0]=0;
        q.push(graph[0][0]);
        vis[0][0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
};*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        queue<int> q;
        for(int start = 0; start < n; start++) {
            if(color[start] != -1)
                continue;
            color[start] = 0;
            q.push(start);
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto it : graph[node]) {
                    if(color[it] == -1) {
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};