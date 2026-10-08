/*struct Node{
    //Node* links[26];
    //bool flag=false;
    Node* links[2];
    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }
    bool containskey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
    links[bit]=node;
}
};

class trie{
public:
    Node* root;
    trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=30;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containskey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
        
    }
    int getmax(int num){
        Node* node=root;
        int maxnum=0;
        for(int i=30;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containskey(1-bit)){
                maxnum=maxnum|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }

        }
        return maxnum;
    }
    ~trie() {
        deleteTree(root);
    }

    void deleteTree(Node* node) {
        if(node == NULL)
            return;

        deleteTree(node->links[0]);
        deleteTree(node->links[1]);

        delete node;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int p=queries.size();
        int u=queries[0].size();
        int m=INT_MAX;
        vector<int>ans(p);
        
        vector<int>num;
        for(int k=0;k<p;k++){
            vector<int>num;
            for(int i=0;i<n;i++){
                if(nums[i]<=queries[k][1]){
                    num.push_back(nums[i]);
                }
            }
            if(num.size()==0){
                ans[k]=-1;
                continue;
            }
            trie t;
            for(int j=0;j<num.size();j++){
                t.insert(num[j]);
            }
            ans[k]=t.getmax(queries[k][0]);
        }
        return ans;
        sort(nums.begin(), nums.end());

        // {x, m, original index}
        vector<vector<int>> q;

        for(int i = 0; i < p; i++) {
            q.push_back({queries[i][0], queries[i][1], i});
        }

        // Sort according to m
        sort(q.begin(), q.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> ans(p);

        trie t;

        int j = 0;

        for(int k = 0; k < p; k++) {
            int x = q[k][0];
            int m = q[k][1];
            int index = q[k][2];

            // Insert all nums <= m
            while(j < n && nums[j] <= m) {
                t.insert(nums[j]);
                j++;
            }

            // No valid number
            if(j == 0) {
                ans[index] = -1;
            }
            else {
                ans[index] = t.getmax(x);
            }
        }

        return ans;
    }
};*/
struct Node {
    int links[2];

    Node() {
        links[0] = -1;
        links[1] = -1;
    }
};

class trie {
public:
    vector<Node> tree;

    trie() {
        tree.push_back(Node());
    }

    void insert(int num) {
        int node = 0;

        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(tree[node].links[bit] == -1) {
                tree[node].links[bit] = tree.size();
                tree.push_back(Node());
            }

            node = tree[node].links[bit];
        }
    }

    int getmax(int num) {
        int node = 0;
        int maxnum = 0;

        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(tree[node].links[1 - bit] != -1) {
                maxnum = maxnum | (1 << i);
                node = tree[node].links[1 - bit];
            }
            else {
                node = tree[node].links[bit];
            }
        }

        return maxnum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int p = queries.size();

        sort(nums.begin(), nums.end());

        // {x, m, original index}
        vector<vector<int>> q;

        for(int i = 0; i < p; i++) {
            q.push_back({queries[i][0], queries[i][1], i});
        }

        // Sort queries according to m
        sort(q.begin(), q.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> ans(p);

        trie t;

        int j = 0;

        for(int k = 0; k < p; k++) {

            int x = q[k][0];
            int m = q[k][1];
            int index = q[k][2];

            // Insert all nums <= m
            while(j < n && nums[j] <= m) {
                t.insert(nums[j]);
                j++;
            }

            if(j == 0) {
                ans[index] = -1;
            }
            else {
                ans[index] = t.getmax(x);
            }
        }

        return ans;
    }
};