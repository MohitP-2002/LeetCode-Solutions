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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int c=0;
        ListNode* n = head;
        while(n!=NULL){
            c++;
            n = n->next;
        }
        int d = c%k;
        int p = c/k;
        if(d>0) p+=1;
        int r=0;
        vector<ListNode*> ans(k);
        n=head;
        int level=0;
        ListNode* prev=NULL;
        while(n!=NULL){
            r++;
            if(r==p){
                d--;
                if(d==0) p-=1;
                prev=n->next;
                n->next=NULL;
                ans[level++]=head;
                head=prev;
                n=head;
                r=0;
                continue;
            }
            // r++;
            n=n->next;
        }
        return ans;
    }
};