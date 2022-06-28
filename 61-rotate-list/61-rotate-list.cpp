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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        ListNode* n = head;
        int c=0;
        while(n){
            n=n->next;
            c++;
        }
        k=k%c;
        while(k--){
            n=head;
            ListNode* prev=head;
            while(n->next!=nullptr){
                prev=n;
                n=n->next;
            }
            n->next=head;
            prev->next=NULL;
            head=n;
        }
        return head;
    }
};