/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prevv=head;
        ListNode *curr=prevv->next;
        ListNode *nextt=curr->next;
        vector<int>arr;
        int i=1;
        while(nextt!=nullptr){
            
            if(curr->val > prevv->val && curr->val >nextt->val){
                arr.push_back(i);
            }
            if(curr->val < prevv->val && curr->val <nextt->val){
                arr.push_back(i);
            }
            i++;
            prevv = curr;
            curr = nextt;
            nextt = nextt->next;
        }
        if(arr.size()<2){
            return {-1,-1};
        }
        
        int maxx=arr[arr.size()-1]-arr[0];
        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++){
            mini=min(mini,abs(arr[i]-arr[i-1]));
        }
        return {mini,maxx};

        

    }
};