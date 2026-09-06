class dsu{
public:
    /*int n;
    vector<int>parent(n,0);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }*/
     vector<int> parent;
    vector<int> rank;

    dsu(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void urank(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(rank[pu]<rank[pv]){
            parent[pu] = pv;

        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }

    }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        dsu d(maxrow+maxcol+2);
        vector<int> used(maxrow+maxcol+2, 0);
        for(auto it:stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            d.urank(noderow,nodecol);
            used[noderow]=1;
            used[nodecol]=1;
        }
        //no of connected components
        int con=0;
        for(int i=0;i<used.size();i++){
            if(used[i] && d.parent[i]==i){
                con++;
            }
        }
        
        return n-con;
    }
};