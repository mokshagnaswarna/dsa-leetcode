class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        //vector<vector<int>>ans;
        
       
        /*for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i].push_back(j);
            }
        }*/
        vector<int>indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < pre.size(); i++){
            int course = pre[i][0];
            int prerequisite = pre[i][1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        
        /*int indegree[numCourses]={0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                indegree[i]++;
            }
        } */
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);

            }
        }
        vector<int>topo;
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
        if(topo.size()!=numCourses){
            return false;
        }
        return true;
       
    }
};