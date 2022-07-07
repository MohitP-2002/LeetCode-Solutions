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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int c=0;
        ListNode* n = head;
        while(n){
            c++;
            n=n->next;
        }
        k=c-k;
        n=head;
        ListNode* prev=NULL;
        while(k--){
            prev=n;
            n=n->next;
        }
        if(head==n) return head->next;
        else if(prev==NULL){
            head->next=n->next;
        }
        else
        prev->next=n->next;
        n->next=NULL;
        return head;
    }
};