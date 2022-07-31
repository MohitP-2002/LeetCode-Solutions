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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* node = head;
        while(node){
            count++;
            node=node->next;
        }
        n=count-n;
        node=head;
        ListNode* prev=NULL;
        while(n--){
            prev=node;
            node=node->next;
        }
        if(prev==NULL) return head->next;
        prev->next=node->next;
        return head;
    }
};