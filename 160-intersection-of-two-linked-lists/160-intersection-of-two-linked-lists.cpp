/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB == nullptr) return NULL;
        while(headA!=NULL){
            ListNode* n= headB;
            while(n!=NULL){
                if(n==headA) return headA;
                n=n->next;
            }
            headA=headA->next;
        }
        return NULL;
    }
};