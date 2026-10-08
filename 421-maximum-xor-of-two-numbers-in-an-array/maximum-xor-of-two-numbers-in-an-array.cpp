struct Node{
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
        for(int i=31;i>=0;i--){
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
        for(int i=31;i>=0;i--){
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
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        trie t;
        for(int i=0;i<n;i++){
            t.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,t.getmax(nums[i]));
        }
        return maxi;
        /*int n=nums.size();
        //int count=0;
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    count=max(count,nums[i]^nums[j]);
                }
            }
        }
        int left=0;
        int right=left+1;
        int count=0;
        while(left<n-1){
            count=max(count,nums[left]^nums[right]);
            right++;
            if(right==n){
                left++;
                right=left+1;
            }
        }
        return count;*/
    }
};