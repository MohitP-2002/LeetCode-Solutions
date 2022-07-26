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
    ListNode* partition(ListNode* head, int x) {
        ListNode* n1 = new ListNode(-1);
        ListNode* n2 = new ListNode(-1);
        ListNode* n=n1,*nn=n2;
        while(head){
            if(head->val<x){
                n->next=new ListNode(head->val);
                n=n->next;
            }
            else{
                nn->next=new ListNode(head->val);
                nn=nn->next;
            }
            head=head->next;
        }
        n->next=n2->next;
        return n1->next;
    }
};