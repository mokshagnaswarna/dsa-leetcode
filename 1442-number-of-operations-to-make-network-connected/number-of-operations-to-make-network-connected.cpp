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

    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu d(n);
        int cnt=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(d.find(u)==d.find(v)){
                cnt++;
            }
            else{
                d.urank(u,v);
            }
            
        }
        int conc=0;
        for(int i=0;i<n;i++){
            if(d.parent[i]==i){
                conc++;
            }
        }
        int ans=-1;
        if(cnt>=conc-1){
            ans=conc-1;
        }
        return ans;
    }
};